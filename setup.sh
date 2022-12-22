#!/bin/sh

python -m venv .venv
source .venv/bin/activate
pip install pybind11==2.10.1
