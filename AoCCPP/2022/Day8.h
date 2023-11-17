#pragma once
#include "IDay.h"
#include <string>
#include <vector>

class Day8_2022 : public IDay {
public:
    void PartOne();
    void PartTwo();

private:
    std::vector<std::string> vec;
    std::vector<std::vector<int>> grid;

    bool CheckTreeVisibility(int x, int y);
};
