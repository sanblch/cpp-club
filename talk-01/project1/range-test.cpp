#include <iostream>
#include <string>
#include <vector>

#include <range/v3/view/filter.hpp>
#include <range/v3/view/transform.hpp>
using std::cout;

int main() {
  std::vector<int> const vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  using namespace ranges;
  auto rng = vi | view::filter([](int i) { return i % 2 == 0; }) |
             view::transform([](int i) { return std::to_string(i); });
  // prints: [2,4,6,8,10]
  cout << rng << '\n';
}
