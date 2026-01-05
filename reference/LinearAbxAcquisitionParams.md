# Linear Antibiotic Acquisition Parameters

Acquisition parameters for LinearAbxModel and LinearAbxModel2.

## Usage

``` r
LinearAbxAcquisitionParams(
  base = Param(0.001),
  time = Param(1, 0),
  mass = Param(1, 1),
  freq = Param(1, 1),
  col_abx = Param(1, 0),
  suss_abx = Param(1, 0),
  suss_ever = Param(1, 0)
)
```

## Arguments

- base:

  The base rate of acquisition (\\\beta_0\\).

- time:

  The time effect on acquisition (\\\beta\_\mathrm{time}\\).

- mass:

  The mass action effect on acquisition (\\\beta\_\mathrm{mass}\\).

- freq:

  The frequency effect on acquisition (\\\beta\_\mathrm{freq}\\).

- col_abx:

  The effect for colonized individuals on antibiotics
  (\\\beta\_{\bullet℞}\\).

- suss_abx:

  The effect on susceptible individuals currently on antibiotics
  (\\\beta\_{\circ℞}\\).

- suss_ever:

  The effect on susceptible individuals ever being on antibiotics
  (\\\beta\_{\circ^\*℞}\\).

## Value

A list of parameters for acquisition.

## Details

Notation: States are represented by circles - susceptible (\\\circ\\),
colonized (\\\bullet\\), latent (\\\circ^\*\\). The symbol ℞ represents
antibiotic effects.

The model for this acquisition model is given by

\$\$ P(\mathrm{Acq(t)}) =
\left\[e^{\beta\_\mathrm{time}(t-t_0)}\right\]\\ \left\\e^{\beta_0}
\left\[ \left( \frac{\beta\_\mathrm{freq}}{P(t)}+(1 -
e^{\beta\_\mathrm{freq}}) \right) e^{\beta\_\mathrm{mass}}\left(
(N\_{\bullet}(t) - N\_{\bullet℞}(t)) +
e^{\beta\_{\bullet℞}}N\_{\bullet℞}(t) \right) + 1 -
e^{\beta\_\mathrm{mass}} \right\] \right\\\\ \left\[ N\_{\circ}(t) -
N\_{\circ^\*℞}(t) + e^{\beta\_{\circ^\*℞}} \left( \left(
N\_{\circ^\*℞}(t) - N\_{\circ℞}(t) \right) +
N\_{\circ℞}(t)e^{\beta\_{\circ℞}} \right) \right\] \$\$ where P(Acq(t))
is the acquisition probability at time t, with effects from time
(\\\beta\_\mathrm{time}\\), mass action (\\\beta\_\mathrm{mass}\\),
frequency dependence (\\\beta\_\mathrm{freq}\\), colonized individuals
on antibiotics (\\\beta\_{\bullet℞}\\), and susceptible individuals
currently (\\\beta\_{\circ℞}\\) or ever (\\\beta\_{\circ^\*℞}\\) on
antibiotics.

## Examples

``` r
LinearAbxAcquisitionParams()
#> $base
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
#> $time
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
#> $mass
#> $init
#> [1] 1
#> 
#> $update
#> [1] TRUE
#> 
#> $prior
#> [1] 1
#> 
#> $weight
#> [1] 1
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> $freq
#> $init
#> [1] 1
#> 
#> $update
#> [1] TRUE
#> 
#> $prior
#> [1] 1
#> 
#> $weight
#> [1] 1
#> 
#> attr(,"class")
#> [1] "Param"
#> 
#> $col_abx
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
#> $suss_abx
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
#> $suss_ever
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
```
