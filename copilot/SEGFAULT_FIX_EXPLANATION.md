# Segfault Fix: LogNormalAbxICP::paramNames() Buffer Overflow

## Root Cause

The segfault was caused by **undefined behavior in `LogNormalAbxICP::paramNames()`** - the function created an empty `std::vector` and then tried to write to indices [0..13], which is writing past the end of the vector.

### The Bug (Before Fix)

```cpp
// src/lognormal/lognormal_LogNormalAbxICP.cpp line 255
std::vector<std::string> LogNormalAbxICP::paramNames() const {
    std::vector<std::string> names;  // Empty vector (size 0)!
    names[0] = "LNAX.time";          // ❌ Writing past end of vector
    names[1] = "LNAX.base";          // ❌ Undefined behavior
    // ... 12 more out-of-bounds writes ...
    return names;
}
```

This caused:
- **Immediate undefined behavior** - writing to unallocated memory
- **Segfault when accessed** - particularly when R's `str()` function tried to enumerate the object's fields
- **Intermittent failures** - depending on memory layout, sometimes "worked" by corrupting nearby memory

### The Fix

```cpp
std::vector<std::string> LogNormalAbxICP::paramNames() const {
    std::vector<std::string> names(14);  // ✓ Pre-allocate for 14 elements
    names[0] = "LNAX.time";
    names[1] = "LNAX.base";
    // ... rest of assignments now valid ...
    return names;
}
```

## Why It Only Failed in Specific Scenarios

The bug was **always present** but only manifested when:

1. **`str()` was called** - This function enumerates all fields, triggering access to `$names`
2. **Interactive R sessions** - Different memory allocator behavior than batch scripts
3. **After certain operations** - Memory layout changes affected whether the corruption was "silent" or crashed

## Secondary Fix: Constructor Parameter Order

Additionally fixed the constructor call in `src/runMCMC.cpp`:

```cpp
// Before: Wrong number of parameters
model = new LogNormalModel(
    nstates,
    modelParameters["nmetro"],     // ❌ Wrong position
    modelParameters["forward"],
    modelParameters["cheat"]
);

// After: Correct 5-parameter call
model = new LogNormalModel(
    nstates,
    0,                             // ✓ abxtest parameter
    modelParameters["nmetro"],     // ✓ nmetro parameter
    modelParameters["forward"],
    modelParameters["cheat"]
);
```

## Verification

After both fixes:
```bash
cd /home/bt/tests
Rscript -e "library(testthat); library(bayestransmission); test_file('testthat/test-lognormalmodel-segfault.R')"
```

Result: ✅ All 4 tests pass, no segfault in any execution mode

## Test That Exposed the Bug

```r
# This would consistently crash before the fix:
library(bayestransmission)
{LogNormalModelParams("LogNormalModel")|>newCppModel()}$InColParams|>str()
```

The crash occurred because:
1. Model created and `InColParams` extracted
2. `str()` called `$names` property
3. `paramNames()` executed with buffer overflow
4. Segfault at address 0x8 (near-null memory)

## Files Modified

1. **`src/lognormal/lognormal_LogNormalAbxICP.cpp`** - Fixed `paramNames()` vector allocation
2. **`src/runMCMC.cpp`** - Fixed `LogNormalModel` constructor call parameter order

## Lessons Learned

1. **Always initialize vector size** - Use `std::vector<T> v(size)` or `.push_back()`, never index into empty vectors
2. **Buffer overflows can be silent** - UB doesn't always crash immediately
3. **Different contexts expose different bugs** - Interactive vs batch, with/without core dumps, etc.
4. **Debug with targeted access** - Instead of `str()`, access specific fields to isolate the failing property
5. **The `ulimit -c unlimited` red herring** - Changed timing/signal handling, masking the real bug
