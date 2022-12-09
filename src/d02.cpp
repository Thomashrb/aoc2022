#include <cstdint>
#include <numeric>
#include <string>
#include <vector>

namespace d02
{
const uint32_t ROCK    = 1;
const uint32_t PAPER   = 2;
const uint32_t SISSORS = 3;
const uint32_t WIN     = 6;
const uint32_t DRAW    = 3;
const uint32_t LOSS    = 0;

int resolve_result_one(std::string line)
{
    if (line == "A X")
    {
        return ROCK + DRAW;
    }  // opponent is ROCK
    if (line == "A Y")
    {
        return PAPER + WIN;
    }
    if (line == "A Z")
    {
        return SISSORS + LOSS;
    }
    if (line == "B X")
    {
        return ROCK + LOSS;
    }  // opponent is PAPER
    if (line == "B Y")
    {
        return PAPER + DRAW;
    }
    if (line == "B Z")
    {
        return SISSORS + WIN;
    }
    if (line == "C X")
    {
        return ROCK + WIN;
    }  // opponent is SISSOR
    if (line == "C Y")
    {
        return PAPER + LOSS;
    }
    if (line == "C Z")
    {
        return SISSORS + DRAW;
    }

    // This should never happen
    return 0;
}

int part_one(std::vector<std::string> guide)
{
    auto resolve_fold = [](uint32_t acc, std::string s) { return acc + resolve_result_one(s); };

    return std::accumulate(guide.begin(), guide.end(), 0, resolve_fold);
}

// X lose
// Y draw
// Z win
int resolve_result_two(std::string line)
{
    if (line == "A X")
    {
        return SISSORS + LOSS;
    }  // opponent is ROCK
    if (line == "A Y")
    {
        return ROCK + DRAW;
    }
    if (line == "A Z")
    {
        return PAPER + WIN;
    }
    if (line == "B X")
    {
        return ROCK + LOSS;
    }  // opponent is PAPER
    if (line == "B Y")
    {
        return PAPER + DRAW;
    }
    if (line == "B Z")
    {
        return SISSORS + WIN;
    }
    if (line == "C X")
    {
        return PAPER + LOSS;
    }  // opponent is SISSOR
    if (line == "C Y")
    {
        return SISSORS + DRAW;
    }
    if (line == "C Z")
    {
        return ROCK + WIN;
    }

    // This should never happen
    return 0;
}

int part_two(std::vector<std::string> guide)
{
    auto resolve_fold = [](uint32_t acc, std::string s) { return acc + resolve_result_two(s); };

    return std::accumulate(guide.begin(), guide.end(), 0, resolve_fold);
};
}  // namespace d02
