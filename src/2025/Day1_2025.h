#pragma once
#include "IDay.h"
#include <vector>
#include <cstdint>

class Day1_2025 : public IDay {
public:
    void PartOne();
    void PartTwo();

    char direction;
    int length;
    int dial = 50;
    int totalZeroes = 0;
    int passedZeroes = 0;
private:
    int getDial();
};