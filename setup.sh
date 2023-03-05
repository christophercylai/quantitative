#!/bin/sh
set -e

rootdir=$(pwd)

pushd ..
mkdir -p quant
cd quant
quantdir=$(pwd)
if [[ ! -d ".venv" ]]; then
    python -m venv .venv
fi
source .venv/bin/activate
pip install pybind11==2.10.1
popd

export PY_FLAGS=$(python3 -m pybind11 --includes)
export PY_EXT=$(python3-config --extension-suffix)

autoreconf -i
mkdir -p build
cd build
../configure
make

cp src/.libs/libquant.so.0.0.0 ${quantdir}
cp ${rootdir}/quant.sh ${quantdir}
cd ${quantdir}
ln -fs libquant.so.0.0.0 quant$(python3-config --extension-suffix)
