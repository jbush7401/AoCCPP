#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day1_2022 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function
private:
    std::vector<std::string> vec;
    std::vector<int> cals;
};