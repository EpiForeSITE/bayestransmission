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
if (FALSE) { # \dontrun{
# Create a linear antibiotic model
params <- LinearAbxModel()
model <- newCppModel(params)

# Extract all parameters
all_params <- getCppModelParams(model)

# View specific parameter groups
all_params$InCol  # In-unit colonization parameters
all_params$Insitu # In situ parameters
} # }
```
