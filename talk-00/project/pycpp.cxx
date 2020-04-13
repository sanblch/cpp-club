#pragma push_macro("slots")
#undef slots
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#pragma pop_macro("slots")
#include <memory.h>

struct Pet {
  Pet(const std::string &name) : name(name) {}
  void setName(const std::string &name_) { name = name_; }
  const std::string &getName() const { return name; }

  std::string name;
};

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<double>);

PYBIND11_MODULE(pycpp, m) {
  py::class_<Pet>(m, "Pet")
      .def(py::init<const std::string &>())
      .def("setName", &Pet::setName)
      .def("getName", &Pet::getName);
}
