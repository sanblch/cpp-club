#include <boost/hana.hpp>
#include <functional>

template <typename Dimensions> struct Quantity {
  double value_;
  explicit Quantity(double v) : value_(v) {}
  explicit operator double() const { return value_; }
  template <typename OtherDimensions>
  explicit Quantity(Quantity<OtherDimensions> other) : value_(other.value_) {
    static_assert(Dimensions{} == OtherDimensions{},
                  "Constructing quantities with incompatible dimensions!");
  }
};

using namespace boost;

// clang-format off
// base dimensions                              M  L  T  I  K  J  N
using mass        = decltype(hana::tuple_c<int, 1, 0, 0, 0, 0, 0, 0>);
using length      = decltype(hana::tuple_c<int, 0, 1, 0, 0, 0, 0, 0>);
using time_       = decltype(hana::tuple_c<int, 0, 0, 1, 0, 0, 0, 0>);
using charge      = decltype(hana::tuple_c<int, 0, 0, 0, 1, 0, 0, 0>);
using temperature = decltype(hana::tuple_c<int, 0, 0, 0, 0, 1, 0, 0>);
using intensity   = decltype(hana::tuple_c<int, 0, 0, 0, 0, 0, 1, 0>);
using amount      = decltype(hana::tuple_c<int, 0, 0, 0, 0, 0, 0, 1>);
// clang-format on

// composite dimensions
// clang-format off
using velocity     = decltype(hana::tuple_c<int, 0, 1, -1, 0, 0, 0, 0>); // M/T
using acceleration = decltype(hana::tuple_c<int, 0, 1, -2, 0, 0, 0, 0>); // M/T^2
using force        = decltype(hana::tuple_c<int, 1, 1, -2, 0, 0, 0, 0>); // ML/T^2
// clang-format on

template <typename D1, typename D2>
auto operator*(Quantity<D1> a, Quantity<D2> b) {
  using D = decltype(hana::zip_with(std::plus<>{}, D1{}, D2{}));
  return Quantity<D>{static_cast<double>(a) * static_cast<double>(b)};
}

template <typename D1, typename D2>
auto operator/(Quantity<D1> a, Quantity<D2> b) {
  using D = decltype(hana::zip_with(std::minus<>{}, D1{}, D2{}));
  return Quantity<D>{static_cast<double>(a) / static_cast<double>(b)};
}

int main() {
  // clang-format off
  Quantity<mass>         m{10.3};
  Quantity<length>       d{3.6};
  Quantity<time_>        t{2.4};
  Quantity<velocity>     v{d / t};
  Quantity<acceleration> a{3.9};
  // Quantity<force>        f{m * v}; // Compiler error!
  Quantity<force>        f{m * a}; // Works as expected
  // clang-format on
}
