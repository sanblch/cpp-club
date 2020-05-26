#include <iostream>
#include <type_traits>

struct Foo {};
struct Bar {};

class Bla {
public:
  template <typename T> static void res(T &, std::true_type) {
    std::cout << "Foo" << std::endl;
  }
  template <typename T> static void res(T &, std::false_type) {
    std::cout << "Bar" << std::endl;
  }
};

int main() {
  int a;
  Foo f;
  Bar b;
  Bla::res<Foo>(f, std::is_same<Foo, Foo>{});
  Bla::res<Bar>(b, std::is_same<Foo, Bar>{});
  Bla::res<int>(a, std::is_same<Foo, int>{});
}
