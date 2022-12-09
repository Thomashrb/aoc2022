#include <stdio.h>  // sscanf

#include <algorithm>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace d04
{
const std::vector<std::pair<std::bitset<128>, bool>> parse_bitsets(std::vector<std::string> ss)
{
    // since we lose context of the original bitsets here return
    // overlaps of bitsets with a full_overlap bool value tacked on
    std::vector<std::pair<std::bitset<128>, bool>> result;

    std::pair<int, int>                           range1;
    std::pair<int, int>                           range2;
    std::pair<std::bitset<128>, std::bitset<128>> bitsets;
    std::bitset<128>                              bitresult;
    for (std::string s : ss)
    {
        bitsets.first.reset();
        bitsets.second.reset();
        bitresult.reset();
        sscanf(s.c_str(), "%d-%d,%d-%d", &range1.first, &range1.second, &range2.first, &range2.second);

        // set bits where position maps to number in range.first - range.second
        for (int i = range1.first; i <= range1.second; i++)
        {
            bitsets.first.set(i);
        }
        for (int i = range2.first; i <= range2.second; i++)
        {
            bitsets.second.set(i);
        }
        // check how many overlaps exist
        bitresult = bitsets.first & bitsets.second;

        result.push_back(
            std::pair(bitresult, bitresult.count() == std::min(bitsets.first.count(), bitsets.second.count())));
    }
    return result;
}

const uint32_t part_one(std::vector<std::string> assignments)
{
    auto count_alloverlap = [](uint32_t acc, std::pair<std::bitset<128>, bool> p)
    {
        if (p.second)
        {
            return acc + 1;
        }
        else
        {
            return acc;
        }
    };

    const auto bitresults = parse_bitsets(assignments);
    return std::accumulate(bitresults.begin(), bitresults.end(), 0, count_alloverlap);
}

const uint32_t part_two(std::vector<std::string> assignments)
{
    auto count_anyoverlap = [](uint32_t acc, std::pair<std::bitset<128>, bool> p)
    {
        if (p.first.any())
        {
            return acc + 1;
        }
        else
        {
            return acc;
        }
    };

    const auto bitresults = parse_bitsets(assignments);
    return std::accumulate(bitresults.begin(), bitresults.end(), 0, count_anyoverlap);
}

}  // namespace d04
