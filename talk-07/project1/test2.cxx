#include <concepts>
#include <iostream>
#include <string>
#include <vector>

template<std::integral T>
std::integral auto sum(T a, T b) { return a + b; }

int main() {
  static_assert(std::integral<int>);

  std::vector<int> vec;
  for(std::integral auto v : vec)
    std::cout << v << std::endl;

  std::integral auto a = sum(5, 3);
  //std::integral auto b = sum("foo", "bar");
}
