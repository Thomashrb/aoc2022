#include <catch2/catch_test_macros.hpp>
#include <d01.cpp>
#include <string>
#include <utils.cpp>
#include <utils.hpp>

const std::vector<std::vector<uint32_t>> test_input = {
    {1000, 2000, 3000}, {4000}, {5000, 6000}, {7000, 8000, 9000}, {10000}};


const std::string raw_input = utils::load_input("d01input.txt");
const std::vector<std::vector<uint32_t>> input = utils::split2numbers(raw_input);

TEST_CASE("Day 01-1 test", "[part 1]") {
  int calories = d01::part_one(::test_input);
  REQUIRE(24000 == calories);
}

TEST_CASE("Day 01-1 real", "[part 1]") {
  int calories = d01::part_one(::input);
  REQUIRE(69883 == calories);
}

TEST_CASE("Day 01-2 test", "[part 2]") {
  int top3_calories = d01::part_two(::test_input);
  REQUIRE(45000 == top3_calories);
}

TEST_CASE("Day 01-2 real", "[part 2]") {
  int top3_calories = d01::part_two(::input);
  REQUIRE(207576 == top3_calories);
}
