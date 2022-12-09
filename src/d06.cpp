#include <cstdint>
#include <numeric>
#include <string>
#include <unordered_set>

namespace d06
{
const uint32_t find_marker_pos(std::string s, uint32_t marker_length)
{
    uint32_t marker_pos = marker_length;

    std::unordered_set<char> marker_set;
    while (marker_pos < s.length() && marker_set.size() < marker_length)
    {
        marker_set.clear();

        for (int i = (marker_pos - marker_length); i < marker_pos; i++)
        {
            marker_set.insert(s.at(i));
        }
        marker_pos++;
    }

    // because we incremented before we checked we have to decrement again
    return marker_pos - 1;
}

const uint32_t part_one(std::string s) { return find_marker_pos(s, 4); }
const uint32_t part_two(std::string s) { return find_marker_pos(s, 14); }

}  // namespace d06
