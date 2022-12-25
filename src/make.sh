set -e

g++ -O3 -Wall -c -fPIC term.cpp -o term.o
g++ -O3 -Wall -c -fPIC $(python3 -m pybind11 --includes) util.cpp -o util.o
g++ -O3 -Wall -c -fPIC $(python3 -m pybind11 --includes) function.cpp -o function.o
g++ -O3 -Wall -c -fPIC $(python3 -m pybind11 --includes) quant.cpp -o quant.o
g++ -O3 -Wall -shared -fPIC $(python3 -m pybind11 --includes) quant.o function.o util.o term.o -o quant$(python3-config --extension-suffix)
rm *.o
