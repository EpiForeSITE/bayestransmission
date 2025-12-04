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
# \donttest{
# Create a linear antibiotic model
params <- LinearAbxModel()
model <- newCppModel(params)

# Extract all parameters
all_params <- getCppModelParams(model)

# View specific parameter groups
all_params$InCol  # In-unit colonization parameters
#>    LABX.base    LABX.time LABX.mass.mx LABX.freq.mx  LABX.colabx  LABX.susabx 
#>        0.001        1.000        1.000        1.000        1.000        1.000 
#> LABX.susever     LABX.clr  LABX.clrAbx LABX.clrEver 
#>        1.000        0.010        1.000        1.000 
all_params$Insitu # In situ parameters
#> Insit.P(unc) Insit.P(col) 
#>          0.9          0.1 
# }
```
