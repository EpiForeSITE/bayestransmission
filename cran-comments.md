This is a resubmission. The previous submission addressed CRAN feedback by changing `\dontrun{}` to `\donttest{}` in documentation examples.

### Additional Changes Since Previous Submission

1. **Package Size Reduction (6% smaller)**
   * Implemented conditional compilation system to reduce binary size
   * Default build: 34 MB (down from 36.3 MB) 
   * Reduced Rcpp template instantiation by ~65% (8,000 vs 23,000 symbols)
   * Full functionality still available via optional compile flags if needed
   * See NEWS.md for details on the three-tier compilation system

2. **Enhanced Testing Infrastructure**
   * Implemented conditional test skipping based on build configuration
   * Created helper functions for runtime detection of exposed classes
   * Added `getExposureFlags()` function for programmatic build inspection
   * Test suite: 304 tests pass with 38 appropriately skipped in minimal build

3. **Code Quality Improvements**
   * Reorganized C++ class exposure into logical tiers (Critical/Testing/Optional)
   * Added stub functions for conditionally compiled exports with informative error messages
   * Improved memory management with shared_ptr caching for container objects
   * Fixed potential segfaults in SystemHistory container access

4. **Package Structure**
   * Moved development-only C++ code out of inst/ to reduce installed package size
   * Added comprehensive documentation for conditional compilation features

### Technical Details for Reviewers

The conditional compilation feature:
* Exposes 8 critical C++ classes by default (essential for all users)
* Optionally exposes 8 additional classes via `-DBAYESTRANSMISSION_COMPREHENSIVE_TESTING`
* Optionally exposes 7 more classes via `-DBAYESTRANSMISSION_ALL_CLASSES`
* All core user-facing functions (runMCMC, model creation, likelihood computation) work identically in all builds
* Tests automatically skip when optional features are not compiled
* No breaking changes for typical users

## Test environments

* Local: Ubuntu 22.04.5 LTS, R 4.5.1
* GitHub Actions (pending): windows-latest, macOS-latest, ubuntu-latest

## R CMD check results

0 errors ✓ | 0 warnings ✓ | 1 note ✓

* This is a new release.

**NOTE on installed package size:**
```
  installed size is 27.5Mb
  sub-directories of 1Mb or more:
    libs  26.5Mb
```

This is expected for a package with extensive C++ code using Rcpp and RcppArmadillo. 
We have already implemented conditional compilation to reduce the binary size by 6% 
(from 36.3 MB to 34 MB on Linux, 26.5 MB on macOS). The size is necessary to provide 
the Bayesian MCMC inference algorithms and likelihood computations for infectious 
disease transmission models. Further size reduction would require removing essential 
functionality.

## Downstream dependencies

There are currently no downstream dependencies for this package.
