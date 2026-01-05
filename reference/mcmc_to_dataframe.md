# Convert MCMC Parameters to Data Frame

Converts the nested list structure of MCMC parameters from `runMCMC`
output into a tidy data frame format suitable for analysis and
visualization.

## Usage

``` r
mcmc_to_dataframe(mcmc_results)
```

## Arguments

- mcmc_results:

  The results object returned by
  [`runMCMC()`](https://epiforesite.github.io/bayestransmission/reference/runMCMC.md).
  Must contain a `Parameters` component and a `LogLikelihood` component.

## Value

A data frame with one row per MCMC iteration containing:

- `iteration`: The iteration number

- `insitu_*`: In-situ probability parameters

- `surv_test_*`: Surveillance test parameters

- `clin_test_*`: Clinical test parameters and rates

- `outunit_*`: Out of unit infection parameters

- `inunit_*`: In unit LinearAbx model parameters (`base`, `time`,
  `mass`, `freq`, `colabx`, `susabx`, `susever`, `clr`, `clrAbx`,
  `clrEver`)

- `abxrate_*`: Antibiotic rate parameters

- `loglikelihood`: Log likelihood at each iteration

## Details

The function extracts parameters from the nested list structure and
handles missing values gracefully by inserting `NA` when a parameter is
not present. This is particularly useful for creating trace plots and
posterior distributions.

## Examples

``` r
results <- runMCMC(data = simulated.data,
  modelParameters = LinearAbxModel(),
  nsims = 10,
  nburn = 0,
  outputparam = TRUE,
  outputfinal = FALSE)
param_df <- mcmc_to_dataframe(results)
head(param_df)
#>   iteration insitu_uncolonized insitu_colonized surv_test_uncol_neg
#> 1         1          0.9999995     4.996876e-07               1e-10
#> 2         2          0.6039819     3.960181e-01               1e-10
#> 3         3          1.0000000     6.897413e-12               1e-10
#> 4         4          0.9999963     3.724572e-06               1e-10
#> 5         5          0.9999996     3.557058e-07               1e-10
#> 6         6          0.7348945     2.651055e-01               1e-10
#>   surv_test_col_neg surv_test_uncol_pos surv_test_col_pos clin_test_uncol
#> 1         0.2182723               1e-10         0.9510191             0.5
#> 2         0.2382038               1e-10         0.9753216             0.5
#> 3         0.2152601               1e-10         0.9996164             0.5
#> 4         0.2960453               1e-10         0.9999991             0.5
#> 5         0.3654798               1e-10         0.6292111             0.5
#> 6         0.4908817               1e-10         0.7923407             0.5
#>   clin_test_col clin_rate_uncol clin_rate_col outunit_acquisition
#> 1           0.5               1             1         0.050000000
#> 2           0.5               1             1         0.050000000
#> 3           0.5               1             1         0.007807676
#> 4           0.5               1             1         0.007807676
#> 5           0.5               1             1         0.003183071
#> 6           0.5               1             1         0.003183071
#>   outunit_clearance inunit_base inunit_time inunit_mass inunit_freq
#> 1       0.010000000 0.001143240           1           1           1
#> 2       0.010000000 0.001290586           1           1           1
#> 3       0.005078576 0.001290586           1           1           1
#> 4       0.005078576 0.001303049           1           1           1
#> 5       0.003845180 0.001179286           1           1           1
#> 6       0.003845180 0.001133930           1           1           1
#>   inunit_colabx inunit_susabx inunit_susever inunit_clr inunit_clrAbx
#> 1             1             1              1 0.01000000             1
#> 2             1             1              1 0.01011653             1
#> 3             1             1              1 0.01058803             1
#> 4             1             1              1 0.01058803             1
#> 5             1             1              1 0.01058803             1
#> 6             1             1              1 0.01305767             1
#>   inunit_clrEver abxrate_uncolonized abxrate_colonized loglikelihood
#> 1              1                   1                 1     -16214.17
#> 2              1                   1                 1     -16197.44
#> 3              1                   1                 1     -15485.44
#> 4              1                   1                 1     -14971.49
#> 5              1                   1                 1     -14493.07
#> 6              1                   1                 1     -14072.01
```
