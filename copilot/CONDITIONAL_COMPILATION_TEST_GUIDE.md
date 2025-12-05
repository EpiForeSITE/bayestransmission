# Conditional Compilation Test Guide

## Build Configurations

The package supports three build configurations controlled by compile flags in `src/Makevars`:

### 1. **Minimal Build** (Default)
No flags required. Smallest binary size (~34MB).

**Exposed Classes:**
- `CppSystem`
- `CppSystemHistory`
- `CppModel` (and derived: `LinearAbxModel`, `LinearAbxModel2`, `LogNormalModel`)
- `util::Random` (via `RRandom`)
- `EpisodeHistory`

**Test Results:** 304 PASS, 38 SKIP, 0 FAIL

### 2. **Comprehensive Testing Build**
Flag: `-DBAYESTRANSMISSION_COMPREHENSIVE_TESTING`

**Additional Exposed Classes:**
- `CppEvent`
- `CppFacility`
- `CppPatient`
- `CppPatientState`
- `CppRawEventList`
- `CppSampler`
- `CppUnit`

**Tests Enabled:** Constructor and method tests for the above classes (11 additional tests)

### 3. **All Classes Build**
Flag: `-DBAYESTRANSMISSION_ALL_CLASSES`

**Additional Exposed Classes:**
- `CppHistoryLink`
- `CppAbxLocationState`
- `CppTestParamsAbx`
- Plus all container access methods

**Additional Exposed Methods:**
- `System$getHistoryLinkList()`
- `System$getEventList()`
- `System$UnitHeads()`
- `System$PatientHeads()`
- `System$FacilityHeads()`
- `System$SystemHead()`
- `System$getPatients()`
- `System$getFacilities()`
- `System$getUnits()`
- `System$getEpisodes()`
- `System$getSystemCounts()`

**Tests Enabled:** All tests including full C++ comparison tests (14 additional tests)

## Test Categorization

### Tests Requiring COMPREHENSIVE_TESTING or Higher

| Test File | Test Name | Class Required |
|-----------|-----------|----------------|
| test-Module-Infect.R | CppFacility methods | CppFacility |
| test-Module-Infect.R | CppPatient constructor | CppPatient |
| test-Module-Infect.R | CppPatientState methods | CppPatientState |
| test-Module-Infect.R | CppRawEventList constructor (3 tests) | CppRawEventList |
| test-Module-Infect.R | CppSampler methods | CppSampler |
| test-Module-Infect.R | CppTestParamsAbx constructor | CppTestParamsAbx |
| test-Module-Infect.R | CppUnit constructor | CppUnit |

**Total:** 11 tests

### Tests Requiring ALL_CLASSES

| Test File | Test Name | Method Required |
|-----------|-----------|-----------------|
| test-Module-Infect.R | UnitHeads test | System$UnitHeads() |
| test-Module-Infect.R | System getEventList (3 tests) | System$getEventList() |
| test-Module-lognormal.R | UnitHeads for lognormal | System$UnitHeads() |
| test-cpp-comparison.R | Colonization link likelihood | System$getHistoryLinkList() |
| test-cpp-comparison.R | Acquisition link likelihood | System$getHistoryLinkList() |
| test-cpp-comparison.R | Discharge link likelihood | System$getHistoryLinkList() |
| test-cpp-comparison.R | Total likelihood check | System$getHistoryLinkList() |
| test-event-likelihoods-simplified.R | Patient access test | System$getPatients() |
| test-event-likelihoods-simplified.R | Link likelihood sum | System$getHistoryLinkList() |
| test-event-likelihoods-simplified.R | Discharge events | System$getHistoryLinkList() |

**Total:** 14 tests

### Always Skipped Tests

These tests are skipped for other reasons (not related to conditional compilation):

- Abstract/base classes: 5 tests
- Interactive MCMC test: 1 test
- Full comparison (needs RUN_FULL_COMPARISON=1): 1 test
- Known numerical discrepancy: 1 test
- LogNormalModelParams constructor issue: 1 test
- Conditional exposure metadata test: 1 test
- Tests needing standalone implementations: 9 tests

**Total:** 19 tests

## Summary

| Configuration | Total Tests | Pass | Skip | Fail |
|---------------|-------------|------|------|------|
| Minimal | 342 | 304 | 38 | 0 |
| Comprehensive Testing | 342 | 315 | 27 | 0 |
| All Classes | 342 | 329 | 13 | 0 |

## Size Impact

| Configuration | Shared Library Size | Symbol Count (estimated) |
|---------------|---------------------|--------------------------|
| Minimal | ~34 MB | ~8,000 |
| Comprehensive Testing | ~38 MB | ~14,000 |
| All Classes | ~42 MB | ~23,000 |

## To Build with Different Configurations

Edit `src/Makevars` and uncomment one of the following lines:

```makefile
# For comprehensive testing (adds event/facility/patient/unit classes):
# PKG_CPPFLAGS += -DBAYESTRANSMISSION_COMPREHENSIVE_TESTING

# For all classes (maximum functionality, largest binary):
# PKG_CPPFLAGS += -DBAYESTRANSMISSION_ALL_CLASSES
```

Then rebuild:
```r
devtools::clean_dll()
devtools::load_all()
```

## CI/CD Recommendations

1. **Default CI:** Run with minimal build to catch issues in core functionality
2. **Extended CI:** Weekly build with ALL_CLASSES flag to ensure full test coverage
3. **CRAN Submission:** Use minimal build for smallest package size
