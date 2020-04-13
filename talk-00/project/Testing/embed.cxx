#include <pybind11/embed.h>
namespace py = pybind11;

int main() {
  py::scoped_interpreter guard{};
  py::exec("print(2+2)");
}
