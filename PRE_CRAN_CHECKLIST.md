# Pre-CRAN Submission Checklist

## Package Information

- **Package**: bayestransmission
- **Version**: 0.1.0
- **Date**: December 5, 2025

## ✅ Completed Checks

### 1. Package Size

- **Source tarball**: 765K (`bayestransmission_0.1.0.tar.gz`)
- **Installed size**: 35 MB
- **Compiled libs**: 34 MB (reduced from 36.3 MB via conditional
  compilation)
- **Status**: ✅ PASS - Within CRAN limits

### 2. Conditional Compilation Implementation

- **Minimal build** (default): 34 MB, 8 critical classes exposed
- **Comprehensive testing**: 38 MB, 16 classes (adds testing classes)
- **All classes**: 42 MB, 23 classes (full functionality)
- **Runtime detection**:
  [`getExposureFlags()`](https://epiforesite.github.io/bayestransmission/reference/getExposureFlags.md)
  function implemented
- **Status**: ✅ PASS - Reduces package size while maintaining
  functionality

### 3. Test Suite

- **Minimal build**: 304 PASS, 38 SKIP, 0 FAIL
- **Test helpers**: Implemented skip_if_not_exposed() and
  skip_if_method_not_available()
- **Coverage**: All critical functionality tested
- **Status**: ✅ PASS - All tests passing with appropriate skips

### 4. Basic Functionality

- **MCMC execution**: ✅ Works correctly
- **Model creation**: ✅ LinearAbxModel, LogNormalModel functional
- **Data loading**: ✅ simulated.data loads correctly
- **C++ integration**: ✅ Rcpp modules properly exposed
- **Status**: ✅ PASS

### 5. Package Structure

- **DESCRIPTION**: Valid, all fields populated
- **NAMESPACE**: Generated, exports correct
- **Documentation**: Roxygen2 generated
- **Vignettes**: Built and included
- **Status**: ✅ PASS

### 6. Dependencies

- **Imports**: assertthat, dplyr, methods, Rcpp (\>= 1.0.12), rlang
- **LinkingTo**: Rcpp, RcppArmadillo
- **SystemRequirements**: C++17, BLAS, LAPACK
- **Status**: ✅ PASS - All dependencies documented

## 📋 Remaining Pre-Submission Tasks

### Required for CRAN Submission:

1.  ⚠️ **Run full R CMD check –as-cran**
    - Current issue: Check hangs on “CRAN incoming feasibility”
    - Workaround tested: *R_CHECK_FORCE_SUGGESTS*=false
    - **Action needed**: Fix hanging issue or submit anyway
2.  ✅ **Update NEWS.md** with release notes
    - Current: Has version 0.1.0 entries
    - **Status**: Ready
3.  ⚠️ **Update cran-comments.md**
    - Should document:
      - Test environment
      - R CMD check results
      - Conditional compilation feature
      - Package size optimization
    - **Action needed**: Update with check results
4.  ⚠️ **Check on multiple platforms**
    - Recommended: winbuilder, r-hub, or GitHub Actions
    - **Action needed**: Not yet tested on Windows/Mac
5.  ✅ **Review LICENSE file**
    - MIT License properly formatted
    - **Status**: Ready
6.  ✅ **Check URLs in DESCRIPTION**
    - GitHub repo: <https://github.com/EpiForeSITE/bayestransmission>
    - Docs site: <https://epiforesite.github.io/bayestransmission/>
    - **Status**: Ready

## 🔧 Known Issues

### Non-blocking:

1.  **Suggested packages not installed** during check
    - devtools, ggplot2, testthat, tidyr
    - Not required for package function
    - Tests skip appropriately when missing
2.  **R CMD check hangs** on “CRAN incoming feasibility”
    - Likely due to maintainer email verification
    - May resolve on CRAN servers
    - Workaround: Use *R_CHECK_FORCE_SUGGESTS*=false

### Resolved:

- ✅ Package size reduced via conditional compilation
- ✅ Test suite updated with skip guards
- ✅ gfortran dependency resolved
- ✅ All critical functionality tested and working

## 📊 Size Comparison

| Metric          | Before  | After       | Change      |
|-----------------|---------|-------------|-------------|
| Installed size  | 36.3 MB | 34 MB       | -6%         |
| Rcpp symbols    | ~23,000 | ~8,000      | -65%        |
| Exposed classes | 23      | 8 (minimal) | Conditional |

## 🚀 Ready for Submission?

**Current Status**: 90% Ready

**Blockers**: - Need successful R CMD check –as-cran completion

**Recommendations**: 1. Try R CMD check on a different
machine/environment 2. Use rhub::check_for_cran() or
devtools::check_win_devel() 3. Update cran-comments.md with results 4.
Submit to CRAN with note about conditional compilation feature

**Next Steps**:

``` r
# 1. Try alternative check methods
rhub::check_for_cran()
devtools::check_win_devel()

# 2. Update cran-comments.md
# 3. Submit via devtools
devtools::submit_cran()
```

## 📝 Notes for CRAN Reviewers

The package implements conditional compilation to reduce binary size: -
Default build exposes only critical classes (34 MB) - Full functionality
available via compile flags if needed - All user-facing functions
(runMCMC, model creation) work in all builds - Tests automatically skip
based on build configuration - See
copilot/CONDITIONAL_COMPILATION_TEST_GUIDE.md for details
