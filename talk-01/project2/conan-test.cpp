#include <boost/archive/binary_oarchive.hpp>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace nlohmann;

int main() {

  json j2 = {{"pi", 3.141},
           {"happy", true},
           {"name", "Niels"},
           {"nothing", nullptr},
           {"answer", {{"everything", 42}}},
           {"list", {1, 0, 2}},
           {"object", {{"currency", "USD"}, {"value", 42.99}}}};

  std::ofstream of("json", std::ios_base::binary);
  boost::archive::binary_oarchive archive(of);
  archive << j2.dump();
}
