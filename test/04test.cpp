#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <d04.cpp>

#include "utils.hpp"

const std::vector<std::string> test_input = {"2-4,6-8", "2-3,4-5", "5-7,7-9", "2-8,3-7", "6-6,4-6", "2-6,4-8"};

const auto raw_input = utils::load_input("d04input.txt");
const auto input     = utils::split(raw_input, '\n');

TEST_CASE("Day 04-1", "[part 1]")
{
    int test   = d04::part_one(::test_input);
    int answer = d04::part_one(::input);

    REQUIRE(2 == test);
    REQUIRE(305 == answer);
}

TEST_CASE("Day 04-2", "[part 2]")
{
    int test   = d04::part_two(::test_input);
    int answer = d04::part_two(::input);

    REQUIRE(4 == test);
    REQUIRE(811 == answer);
}
