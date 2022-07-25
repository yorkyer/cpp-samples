#include <pybind11/pybind11.h>
#include <mult.hpp>

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // Optional module docstring
    m.def("cpp_function", &cmult, "A function that multiplies two numbers");
}