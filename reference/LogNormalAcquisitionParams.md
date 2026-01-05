# Log-Normal Acquisition Parameters

Acquisition parameters for the log-normal model (LogNormalAbxICP). This
model has 8 acquisition parameters accessed by index in C++. Note: When
accessed via setupLogNormalICPAcquisition, parameters are set by index,
so this returns an unnamed list where position matters.

## Usage

``` r
LogNormalAcquisitionParams(
  time = Param(0, 0),
  constant = Param(0.001, 1),
  log_tot_inpat = Param(-1, 0),
  log_col = Param(1, 0),
  col = Param(0, 0),
  abx_col = Param(0, 0),
  onabx = Param(0, 0),
  everabx = Param(0, 0)
)
```

## Arguments

- time:

  Time parameter (index 0) (\\\beta_t\\)

- constant:

  Constant parameter (index 1) (\\\beta_0\\)

- log_tot_inpat:

  Log total in-patients parameter (index 2)

- log_col:

  Log number colonized parameter (index 3) (\\\beta_c\\)

- col:

  Number colonized parameter (index 4)

- abx_col:

  Number of colonized individuals on antibiotics parameter (index 5)
  (\\\beta\_{\bullet℞}\\)

- onabx:

  Susceptible patient currently on antibiotics effect (index 6)
  (\\\beta\_{\circ℞}\\)

- everabx:

  Susceptible patient ever on antibiotics effect (index 7)
  (\\\beta\_{\circ^\*℞}\\)

## Value

An unnamed list of 8 parameters in the correct order for
LogNormalAbxICP.

## Examples

``` r
LogNormalAcquisitionParams()
#> [[1]]
#> $init
#> [1] 0
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] 0
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[2]]
#> $init
#> [1] 0.001
#> 
#> $update
#> [1] TRUE
#> 
#> $prior
#> [1] 0.001
#> 
#> $weight
#> [1] 1
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[3]]
#> $init
#> [1] -1
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] -1
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[4]]
#> $init
#> [1] 1
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] 1
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[5]]
#> $init
#> [1] 0
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] 0
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[6]]
#> $init
#> [1] 0
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] 0
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[7]]
#> $init
#> [1] 0
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] 0
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> [[8]]
#> $init
#> [1] 0
#> 
#> $update
#> [1] FALSE
#> 
#> $prior
#> [1] 0
#> 
#> $weight
#> [1] 0
#> 
#> attr(,"class")
#> [1] "Param"
#> 
```
