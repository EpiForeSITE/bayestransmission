# Run Bayesian Transmission MCMC

Run Bayesian Transmission MCMC

## Usage

``` r
runMCMC(
  data,
  modelParameters,
  nsims,
  nburn = 100L,
  outputparam = TRUE,
  outputfinal = FALSE,
  verbose = FALSE
)
```

## Arguments

- data:

  Data frame with columns, in order: facility, unit, time, patient, and
  event type.

- modelParameters:

  List of model parameters, see .

- nsims:

  Number of MCMC samples to collect after burn-in.

- nburn:

  Number of burn-in iterations.

- outputparam:

  Whether to output parameter values at each iteration.

- outputfinal:

  Whether to output the final model state.

- verbose:

  Print progress messages.

## Value

A list with the following elements:

- `Parameters` the MCMC chain of model parameters (if outputparam=TRUE)

- `LogLikelihood` the log likelihood of the model at each iteration (if
  outputparam=TRUE)

- `MCMCParameters` the MCMC parameters used

- `ModelParameters` the model parameters used

- `ModelName` the name of the model

- `nstates` the number of states in the model

- `waic1` the WAIC1 estimate

- `waic2` the WAIC2 estimate

- and optionally (if outputfinal=TRUE) `FinalModel` the final model
  state.

## See also

[mcmc_to_dataframe](https://epiforesite.github.io/bayestransmission/reference/mcmc_to_dataframe.md)

## Examples

``` r
  # Minimal example: create parameters and run a very short MCMC
  params <- LinearAbxModel(nstates = 2)
  data(simulated.data_sorted, package = "bayestransmission")
  results <- runMCMC(
    data = simulated.data_sorted,
    modelParameters = params,
    nsims = 3,
    nburn = 0,
    outputparam = TRUE,
    outputfinal = FALSE,
    verbose = FALSE
  )
  str(results)
#> List of 6
#>  $ Parameters     :List of 3
#>   ..$ :List of 6
#>   .. ..$ Insitu          : Named num [1:2] 0.99593 0.00407
#>   .. .. ..- attr(*, "names")= chr [1:2] "Insit.P(unc)" "Insit.P(col)"
#>   .. ..$ SurveillanceTest: Named num [1:4] 1.00e-10 2.26e-01 1.00e-10 1.00
#>   .. .. ..- attr(*, "names")= chr [1:4] "ATest.P(+|unc-)" "ATest.P(+|col-)" "ATest.P(+|unc+)" "ATest.P(+|col+)"
#>   .. ..$ ClinicalTest    : Named num [1:4] 0.5 0.5 1 1
#>   .. .. ..- attr(*, "names")= chr [1:4] "RTest.P(+|unc)" "RTest.P(+|col)" "RTest.rateUnc" "RTest.rateCol"
#>   .. ..$ OutCol          : Named num [1:2] 0.05 0.01
#>   .. .. ..- attr(*, "names")= chr [1:2] "Out.acq" "Out.clr"
#>   .. ..$ InCol           : Named num [1:10] 0.000892 1 1 1 1 ...
#>   .. .. ..- attr(*, "names")= chr [1:10] "LABX.base" "LABX.time" "LABX.mass.mx" "LABX.freq.mx" ...
#>   .. ..$ Abx             : Named num [1:2] 1 1
#>   .. .. ..- attr(*, "names")= chr [1:2] "Abx.rateUnc" "Abx.rateCol"
#>   ..$ :List of 6
#>   .. ..$ Insitu          : Named num [1:2] 0.99896 0.00104
#>   .. .. ..- attr(*, "names")= chr [1:2] "Insit.P(unc)" "Insit.P(col)"
#>   .. ..$ SurveillanceTest: Named num [1:4] 1.00e-10 2.39e-01 1.00e-10 7.39e-01
#>   .. .. ..- attr(*, "names")= chr [1:4] "ATest.P(+|unc-)" "ATest.P(+|col-)" "ATest.P(+|unc+)" "ATest.P(+|col+)"
#>   .. ..$ ClinicalTest    : Named num [1:4] 0.5 0.5 1 1
#>   .. .. ..- attr(*, "names")= chr [1:4] "RTest.P(+|unc)" "RTest.P(+|col)" "RTest.rateUnc" "RTest.rateCol"
#>   .. ..$ OutCol          : Named num [1:2] 0.00705 0.00723
#>   .. .. ..- attr(*, "names")= chr [1:2] "Out.acq" "Out.clr"
#>   .. ..$ InCol           : Named num [1:10] 0.000907 1 1 1 1 ...
#>   .. .. ..- attr(*, "names")= chr [1:10] "LABX.base" "LABX.time" "LABX.mass.mx" "LABX.freq.mx" ...
#>   .. ..$ Abx             : Named num [1:2] 1 1
#>   .. .. ..- attr(*, "names")= chr [1:2] "Abx.rateUnc" "Abx.rateCol"
#>   ..$ :List of 6
#>   .. ..$ Insitu          : Named num [1:2] 0.668 0.332
#>   .. .. ..- attr(*, "names")= chr [1:2] "Insit.P(unc)" "Insit.P(col)"
#>   .. ..$ SurveillanceTest: Named num [1:4] 1.00e-10 3.83e-01 1.00e-10 6.71e-01
#>   .. .. ..- attr(*, "names")= chr [1:4] "ATest.P(+|unc-)" "ATest.P(+|col-)" "ATest.P(+|unc+)" "ATest.P(+|col+)"
#>   .. ..$ ClinicalTest    : Named num [1:4] 0.5 0.5 1 1
#>   .. .. ..- attr(*, "names")= chr [1:4] "RTest.P(+|unc)" "RTest.P(+|col)" "RTest.rateUnc" "RTest.rateCol"
#>   .. ..$ OutCol          : Named num [1:2] 0.00705 0.00723
#>   .. .. ..- attr(*, "names")= chr [1:2] "Out.acq" "Out.clr"
#>   .. ..$ InCol           : Named num [1:10] 0.000909 1 1 1 1 ...
#>   .. .. ..- attr(*, "names")= chr [1:10] "LABX.base" "LABX.time" "LABX.mass.mx" "LABX.freq.mx" ...
#>   .. ..$ Abx             : Named num [1:2] 1 1
#>   .. .. ..- attr(*, "names")= chr [1:2] "Abx.rateUnc" "Abx.rateCol"
#>  $ LogLikelihood  : num [1:3] -16088 -15270 -14472
#>  $ MCMCParameters :List of 4
#>   ..$ nsims      : num 3
#>   ..$ nburn      : num 0
#>   ..$ outputparam: logi TRUE
#>   ..$ outputfinal: logi FALSE
#>  $ ModelParameters:List of 12
#>   ..$ modname         : chr "LinearAbxModel"
#>   ..$ nstates         : int 2
#>   ..$ nmetro          : int 1
#>   ..$ forward         : logi TRUE
#>   ..$ cheat           : logi FALSE
#>   ..$ Insitu          :List of 3
#>   .. ..$ probs : num [1:3] 0.9 0 0.1
#>   .. ..$ priors: num [1:3] 0.9 1 0.1
#>   .. ..$ doit  : logi [1:3] TRUE FALSE TRUE
#>   ..$ SurveillanceTest:List of 3
#>   .. ..$ colonized  :List of 4
#>   .. .. ..$ init  : num 0.8
#>   .. .. ..$ update: logi TRUE
#>   .. .. ..$ prior : num 0.8
#>   .. .. ..$ weight: num 1
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ uncolonized:List of 4
#>   .. .. ..$ init  : num 1e-10
#>   .. .. ..$ update: logi FALSE
#>   .. .. ..$ prior : num 1e-10
#>   .. .. ..$ weight: num 0
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ latent     :List of 4
#>   .. .. ..$ init  : num 0
#>   .. .. ..$ update: logi FALSE
#>   .. .. ..$ prior : num 0
#>   .. .. ..$ weight: num 0
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   ..$ ClinicalTest    :List of 3
#>   .. ..$ uncolonized:List of 2
#>   .. .. ..$ param:List of 4
#>   .. .. .. ..$ init  : num 0.5
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 0.5
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ rate :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ colonized  :List of 2
#>   .. .. ..$ param:List of 4
#>   .. .. .. ..$ init  : num 0.5
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 0.5
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ rate :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ latent     :List of 2
#>   .. .. ..$ param:List of 4
#>   .. .. .. ..$ init  : num 0
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 0
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ rate :List of 4
#>   .. .. .. ..$ init  : num 0
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 0
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   ..$ OutCol          :List of 3
#>   .. ..$ acquisition:List of 4
#>   .. .. ..$ init  : num 0.05
#>   .. .. ..$ update: logi TRUE
#>   .. .. ..$ prior : num 0.05
#>   .. .. ..$ weight: num 1
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ clearance  :List of 4
#>   .. .. ..$ init  : num 0.01
#>   .. .. ..$ update: logi TRUE
#>   .. .. ..$ prior : num 0.01
#>   .. .. ..$ weight: num 1
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ progression:List of 4
#>   .. .. ..$ init  : num 0
#>   .. .. ..$ update: logi FALSE
#>   .. .. ..$ prior : num 0
#>   .. .. ..$ weight: num 0
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   ..$ InCol           :List of 3
#>   .. ..$ acquisition:List of 7
#>   .. .. ..$ base     :List of 4
#>   .. .. .. ..$ init  : num 0.001
#>   .. .. .. ..$ update: logi TRUE
#>   .. .. .. ..$ prior : num 0.001
#>   .. .. .. ..$ weight: num 1
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ time     :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ mass     :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi TRUE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 1
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ freq     :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi TRUE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 1
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ col_abx  :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ suss_abx :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ suss_ever:List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ progression:List of 3
#>   .. .. ..$ rate    :List of 4
#>   .. .. .. ..$ init  : num 0.01
#>   .. .. .. ..$ update: logi TRUE
#>   .. .. .. ..$ prior : num 0.01
#>   .. .. .. ..$ weight: num 1
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ abx     :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ ever_abx:List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ clearance  :List of 3
#>   .. .. ..$ rate    :List of 4
#>   .. .. .. ..$ init  : num 0.01
#>   .. .. .. ..$ update: logi TRUE
#>   .. .. .. ..$ prior : num 0.01
#>   .. .. .. ..$ weight: num 1
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ abx     :List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   .. .. ..$ ever_abx:List of 4
#>   .. .. .. ..$ init  : num 1
#>   .. .. .. ..$ update: logi FALSE
#>   .. .. .. ..$ prior : num 1
#>   .. .. .. ..$ weight: num 0
#>   .. .. .. ..- attr(*, "class")= chr "Param"
#>   ..$ Abx             :List of 3
#>   .. ..$ onoff: logi FALSE
#>   .. ..$ delay: num 0
#>   .. ..$ life : num 1
#>   ..$ AbxRate         :List of 3
#>   .. ..$ uncolonized:List of 4
#>   .. .. ..$ init  : num 1
#>   .. .. ..$ update: logi FALSE
#>   .. .. ..$ prior : num 1
#>   .. .. ..$ weight: num 0
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ colonized  :List of 4
#>   .. .. ..$ init  : num 1
#>   .. .. ..$ update: logi FALSE
#>   .. .. ..$ prior : num 1
#>   .. .. ..$ weight: num 0
#>   .. .. ..- attr(*, "class")= chr "Param"
#>   .. ..$ latent     :List of 4
#>   .. .. ..$ init  : num 0
#>   .. .. ..$ update: logi FALSE
#>   .. .. ..$ prior : num 0
#>   .. .. ..$ weight: num 0
#>   .. .. ..- attr(*, "class")= chr "Param"
#>  $ waic1          : num 0.422
#>  $ waic2          : num 0.486
```
