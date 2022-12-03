#include "utils.hpp"
#include <catch2/catch_test_macros.hpp>
#include <d03.cpp>
#include <string>

const std::vector<std::string> test_input =
{"vJrwpWtwJgWrhcsFMMfFFhFp",
"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
"PmmdzqPrVvPwwTWBwg",
"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
"ttgJtRGJQctTZtZT",
"CrZsJsPPZsGzwwsLwLmpwMDw"};


const auto raw_input = utils::load_input("d03input.txt");
const auto input = utils::split(raw_input, '\n');

TEST_CASE("Day 03-1", "[part 1]") {
  int test = d03::part_one(::test_input);
  int answer = d03::part_one(::input);

  REQUIRE(157 == test);
  REQUIRE(8515 == answer);
}

TEST_CASE("Day 03-2", "[part 2]") {
  int test = d03::part_two(::test_input);
  int answer = d03::part_two(::input);

  REQUIRE(70 == test);
  REQUIRE(2434 == answer);
}
