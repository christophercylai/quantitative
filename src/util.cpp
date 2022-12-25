#include <pybind11/pybind11.h>
#include <iostream>
#include <string>
#include <stdexcept>

namespace py = pybind11;


void assertTrue(const bool& b, const std::string& msg) {
    if (!b) {
        throw std::runtime_error(msg);
    }
}

void printMsg(const std::string& msg) {
    py::print(msg);
}
