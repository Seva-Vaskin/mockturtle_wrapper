#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "cut_enumerates.h"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(mockturtle_wrapper, m) {
    m.doc() = "Example doc";
    m.def("add", &add, "Add two numbers");
    m.def("enumerate_cuts", &enumerate_cuts, "Enumerates cuts, lol :)");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
