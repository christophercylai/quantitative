# Quantitative Solver

## Development Environments
* Developed and compiled on Fedora (Fedora release 36)
* Compiler: gcc version 12.2.1 20221121 (Red Hat 12.2.1-4) (GCC)

## Required Packages
* gcc-12.2.1
* python3-devel-3.10.9
* autoconf-2.71-3
* automake-1.16.5-7
* libtool-2.4.7-1
* Make-4.3

## Setup
```
# 1. Setup Python virutalenv and install pybind11 in ../quant
# 2. run 'autotools', 'configure' and 'make' to generate the quant python library
./setup.sh

# quant python library ready to be used in ../quant
cd ../quant
./quant.sh
>>> import quant
```

## Development Ettiquette
* Variables naming examples:
    * hello
    * hello_world
* Funcions naming examples:
    * function
    * myFunc
* Classes naming examples:
    * Class
    * MyClass
