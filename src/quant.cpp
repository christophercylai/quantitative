#include <pybind11/pybind11.h>
#include <string>
#include <iostream>
#include "function.h"
#include "util.h"

namespace py = pybind11;


PYBIND11_MODULE(quant, m) {
    m.doc() = "Quantitative Solver";
    m.def("printMsg", &printMsg, "A function that prints the given message", py::arg("msg"));

    py::class_<Function>(m, "Function")
        .def(py::init<const std::string&>())
        .def("getFuncStr", &Function::getFuncStr, "Print the function");
}
