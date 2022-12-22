#include <pybind11/pybind11.h>
#include <string>
#include "function.h"

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(quant, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");

    py::class_<Function>(m, "Function")
        .def(py::init<const std::string &>())
        .def("printFunc", &Function::printFunc);
}
