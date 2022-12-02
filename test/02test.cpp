#include "utils.hpp"
#include <catch2/catch_test_macros.hpp>
#include <d02.cpp>
#include <string>

const std::vector<std::string> test_input = {"A Y", "B X", "C Z"};

const auto raw_input = utils::load_input("d02input.txt");
const auto input = utils::split(raw_input, '\n');

TEST_CASE("Day 02-1", "[part 1]") {
  int test = d02::part_one(::test_input);
  int answer = d02::part_one(::input);

  REQUIRE(15 == test);
  REQUIRE(14069 == answer);
}

TEST_CASE("Day 02-2", "[part 2]") {
  int test = d02::part_two(::test_input);
  int answer = d02::part_two(::input);

  REQUIRE(12 == test);
  REQUIRE(12411 == answer);
}
