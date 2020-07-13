#include <concepts>
#include <iostream>
#include <iterator>
#include <vector>

// clang-format off
template<typename C>
concept StdContainer = requires (C c) {
    typename C::iterator;
    typename C::value_type;
    {std::begin(c)} -> std::same_as<typename C::iterator>;
    {std::end(c)} -> std::same_as<typename C::iterator>;
    {std::next(std::begin(c))} -> std::same_as<typename C::iterator>;
    {*std::begin(c)} -> std::convertible_to<typename C::value_type>;
    {c.size()} -> std::convertible_to<size_t>;
};
// clang-format on

template <StdContainer C>
void fun1(const C& c) {
  for(const auto& i : c)
    std::cout << i << std::endl;
}

void fun2(const StdContainer auto &c) {
  for (const auto &i : c)
    std::cout << i << std::endl;
}

int main() {
  std::vector<int> vec{1,2,3};
  fun1(vec);
  fun2(vec);
}
