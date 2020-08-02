#include <boost/date_time/gregorian/gregorian.hpp>
#include <gtest/gtest.h>
#include <iterator>
#include <ranges>
#include <vector>

namespace greg = boost::gregorian;
using date = greg::date;
using day = greg::date_duration;
using namespace std::ranges;

namespace boost {
namespace gregorian {
date &operator++(date &d) { return d = d + day(1); }
date operator++(date &d, int) { return ++d - day(1); }
} // namespace gregorian
} // namespace boost

template <> struct std::incrementable_traits<date> {
  using difference_type = date::duration_type::duration_rep::int_type;
};

TEST(ranges, iota) {
  date from(2015, greg::Jan, 1);
  date to(2016, greg::Jan, 1);
  for(auto i : views::iota(from, to) | views::take(10))
    std::cout << i << std::endl;
}

auto dates_in_year(int year) {
  return views::iota(date{year, greg::Jan, 1}, date{year + 1, greg::Jan, 1});
}

TEST(ranges, month) {
  auto year = dates_in_year(2015);
}

template <class Rng>
class chunk_view : public view_interface<chunk_view<Rng>> {
  std::size_t n_;
  class adaptor;
  adaptor begin_adaptor() {
    return adaptor{n_, end(this->base())};
  }
public:
  chunk_view() = default;
  chunk_view(Rng rng, std::size_t n) : view_interface<chunk_view>(std::move(rng)), n_(n) {}
};

template <class Rng>
class chunk_view<Rng>::adaptor {
  ;
};

TEST(ranges, chunk) {
  std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
  // for(auto i : v | view::chunk(3))
  //   std::cout << i << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

