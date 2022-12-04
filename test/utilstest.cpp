#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <string>
#include <utils.cpp>
#include <utils.hpp>
#include <vector>

const auto raw_input = utils::load_input("d01input.txt");

TEST_CASE("load_input loads ... something") {
  REQUIRE(raw_input.length() != 0);
}

TEST_CASE("split splits on newline") {
  const auto s = "1\n2\n3\n4\n";
  const std::vector<std::string> n = {"1", "2", "3", "4"};
  const auto strings = utils::split(s, '\n');

  REQUIRE(strings == n);
}

TEST_CASE("split splits on whitespace") {
  const auto s = "1 2 3 4";
  const std::vector<std::string> n = {"1", "2", "3", "4"};
  const auto strings = utils::split(s, ' ');

  REQUIRE(strings == n);
}
