#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <string>
#include <utils.cpp>
#include <utils.hpp>
#include <vector>

const auto raw_input = utils::load_input("/tmp/d01input.txt");

TEST_CASE("load_input loads ... something") {
  REQUIRE(raw_input.length() != 0);
}

TEST_CASE("split2numbers splits to numbers") {
  const auto s = "1\n2\n\n3\n4\n\n";
  const std::vector<std::vector<uint32_t>> n = {{1, 2}, {3, 4}};
  const auto numbers = utils::split2numbers(s);

  REQUIRE(numbers == n);
}
