#include <iostream>
#include <type_traits>

struct Foo {};
struct Bar {};

template <bool B, class T> struct enable_if {};
template <class T> struct enable_if<true, T> { using type = T; };

class Bla {
public:
  template <typename T>
  static typename enable_if<std::is_same_v<Foo, T>, void>::type res(T &) {
    std::cout << "Foo" << std::endl;
  }
  template <typename T>
  static typename enable_if<!std::is_same_v<Foo, T>, void>::type res(T &) {
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
