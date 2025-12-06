# Get compilation flags for exposed classes

Returns information about which optional classes are exposed in this
build. This allows tests to conditionally skip tests for unexposed
classes.

## Usage

``` r
getExposureFlags()
```

## Value

List with logical flags:

- `comprehensive_testing` - TRUE if comprehensive testing classes are
  exposed

- `all_classes` - TRUE if all optional classes are exposed

- `minimal` - TRUE if only critical classes are exposed
