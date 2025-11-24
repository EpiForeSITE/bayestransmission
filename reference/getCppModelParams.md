# Extract Model Parameters from C++ Model Object

Convenience function to extract all parameter values from a C++ model
object created with
[`newCppModel()`](https://epiforesite.github.io/bayestransmission/reference/newCppModel.md).
This is essentially a wrapper around accessing the model's parameter
properties.

## Usage

``` r
getCppModelParams(model)
```

## Arguments

- model:

  A C++ model object created with
  [`newCppModel()`](https://epiforesite.github.io/bayestransmission/reference/newCppModel.md)

## Value

A named list containing all model parameter values:

- `Insitu` - Named numeric vector of in situ parameter values

- `SurveillanceTest` - Named numeric vector of surveillance test
  parameter values

- `ClinicalTest` - Named numeric vector of clinical test parameter
  values

- `OutCol` - Named numeric vector of out-of-unit colonization parameter
  values

- `InCol` - Named numeric vector of in-unit colonization parameter
  values

- `Abx` - Named numeric vector of antibiotic parameter values (if
  applicable)

If a component's names cannot be determined or lengths mismatch, the
vector is returned unnamed.

## Examples

``` r
params <- LinearAbxModel()
model <- newCppModel(params)

# Extract all parameters
getCppModelParams(model)
#> $Insitu
#> Insit.P(unc) Insit.P(col) 
#>          0.9          0.1 
#> 
#> $SurveillanceTest
#> ATest.P(+|unc-) ATest.P(+|col-) ATest.P(+|unc+) ATest.P(+|col+) 
#>           1e-10           8e-01           1e-10           8e-01 
#> 
#> $ClinicalTest
#> RTest.P(+|unc) RTest.P(+|col)  RTest.rateUnc  RTest.rateCol 
#>            0.5            0.5            1.0            1.0 
#> 
#> $OutCol
#> Out.acq Out.clr 
#>    0.05    0.01 
#> 
#> $InCol
#>    LABX.base    LABX.time LABX.mass.mx LABX.freq.mx  LABX.colabx  LABX.susabx 
#>        0.001        1.000        1.000        1.000        1.000        1.000 
#> LABX.susever     LABX.clr  LABX.clrAbx LABX.clrEver 
#>        1.000        0.010        1.000        1.000 
#> 
#> $Abx
#> Abx.rateUnc Abx.rateCol 
#>           1           1 
#> 
```
