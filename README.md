# Task 4 - State Data with File I/O

## Overview

Console application for processing country/state data using text files.
Reads state data, filters European states with population > 8 million,
saves results to output file. Variant 37.

## Author

anichkay

## Usage

```bash
make
./bin/states
```

The program will:
1. Read state data from `data/states.txt` (or input from keyboard)
2. Display all states
3. Filter European states with population > 8 million
4. Save filtered results to `data/result.txt`

### Data format

Pipe-delimited text file (`|` separator):
```
Country|Capital|Language|Population|Area|Currency|Government|Head|Continent
```

## Additional Notes

- Project follows CIS (Client-Interface-Server) model
- Built with `make`, CI via GitHub Actions
