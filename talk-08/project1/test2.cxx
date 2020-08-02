#include <iostream>
#include <ranges>
#include <vector>

auto even = [](int i) { return 0 == i % 2; };
auto square = [](int i) { return i * i; };

auto even_square() {
  return std::views::filter(even) | std::views::transform(square);
}

int main() {
  std::vector<int> ints{0, 1, 2, 3, 4, 5};

  for (int i : ints | even_square()) {
    std::cout << i << ' ';
  }
}
