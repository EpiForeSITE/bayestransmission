# .Rprofile for bayestransmission package development
# This file is automatically sourced when R starts in this directory

# Add development packages to default packages
local({
  # Get current default packages
  default_packages <- getOption("defaultPackages")
  
  # Add devtools and usethis if not already present
  dev_packages <- c("devtools", "usethis")
  missing_packages <- setdiff(dev_packages, default_packages)
  
  if (length(missing_packages) > 0) {
    options(defaultPackages = c(default_packages, missing_packages))
  }
  
  # Print a message to confirm loading
  cat("Loading development environment for bayestransmission package...\n")
  cat("Added to default packages:", paste(dev_packages, collapse = ", "), "\n")
})

# Optional: Set some useful options for package development
options(
  # Show more detailed error messages
  error = quote(utils::dump.frames("last.dump", dumpto = "last.dump")),
  
  # Set CRAN repository
  repos = c(CRAN = "https://cran.rstudio.com/"),
  
  # Enable tibble printing
  tibble.print_max = 100,
  tibble.print_min = 10
)

# Clean up
rm(list = ls())