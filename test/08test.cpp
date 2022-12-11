#include <catch2/catch_test_macros.hpp>
#include <d08.cpp>

#include "utils.hpp"

std::vector<std::string> test_input =
{ "30373",
  "25512",
  "65332",
  "33549",
  "35390", };

const auto raw_input = utils::load_input("d08input.txt");
const auto input = utils::split(raw_input, '\n');

TEST_CASE("Day 08-1", "[part 1]")
{
    auto test  = d08::part_one(::test_input);
//    auto answer = d08::part_one(::input);

    REQUIRE(21 == test);
//    REQUIRE(21 == answer);
}

//TEST_CASE("Day 08-2", "[part 2]")
//{
//}
