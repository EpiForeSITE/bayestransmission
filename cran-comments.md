This is a patch release fixing a bug in LinearAbxModel constructors.

## Changes in This Version

* Fixed undefined behavior in LinearAbxModel and LinearAbxModel2 constructors that caused incorrect parent constructor parameter mapping
* This bug was detected by UBSAN (Undefined Behavior Sanitizer) and could cause downcast errors
* No user-facing API changes

## Test environments

* Local: Ubuntu 22.04.5 LTS, R 4.5.1
* GitHub Actions (pending): windows-latest, macOS-latest, ubuntu-latest

## R CMD check results

0 errors ✓ | 0 warnings ✓ | 0 notes ✓

**NOTE on installed package size (from initial release):**
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
