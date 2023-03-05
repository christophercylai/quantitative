#!/bin/sh

set -e

if [[ -d ".venv" ]]; then
    python -m venv .venv
    source .venv/bin/activate
    pip install pybind11==2.10.1
fi
