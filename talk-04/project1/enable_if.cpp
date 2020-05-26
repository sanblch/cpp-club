#include <iostream>
#include <type_traits>

struct Foo {};
struct Bar {};

class Bla {
public:
  template <typename T>
  static std::enable_if_t<std::is_same_v<Foo, T>, void> res(T &) {
    std::cout << "Foo" << std::endl;
  }
  template <typename T>
  static std::enable_if_t<!std::is_same_v<Foo, T>, void> res(T &) {
    std::cout << "Bar" << std::endl;
  }
};

int main() {
  int a;
  Foo f;
  Bar b;
  Bla::res<Foo>(f);
  Bla::res<Bar>(b);
  Bla::res<int>(a);
}
