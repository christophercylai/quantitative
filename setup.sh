#!/bin/sh

set -e

if [[ ! -d ".venv" ]]; then
    python -m venv .venv
    source .venv/bin/activate
    pip install pybind11==2.10.1
fi

export PY_FLAGS=$(python3 -m pybind11 --includes)
export PY_EXT=$(python3-config --extension-suffix)

autoreconf -i
mkdir -p build
cd build
../configure
make
