#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day2_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function
    std::vector<std::string> vec;

    enum Color{none, blue, red, green};
    int powerOf = 0;
    struct CubesRevealed {
        CubesRevealed(int c = 0, Color co = none) : count(c), color(co) {};
        int count = 0;
        Color color;
    };

    struct Subset {
        std::vector<CubesRevealed> cubesRevealed = {};
    };

    class Game {
    public:
        int gameId = 0;
        std::vector<Subset> subsets = {};
    };
};