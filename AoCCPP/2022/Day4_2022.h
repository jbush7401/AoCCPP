#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day4_2022 : public IDay {
public:
    void PartOne(); 
    void PartTwo(); 

private:
    struct Digit {
        int d1, d2, d3, d4;
        Digit(int i1, int i2, int i3, int i4) : d1(i1), d2(i2), d3(i3), d4(i4) {};
    };
    std::vector<Digit> nums;
    std::vector<std::string> vec;
};