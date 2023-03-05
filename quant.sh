#!/bin/sh
set -e

source .venv/bin/activate
export LD_LIBRARY_PATH=$(pwd)
python
