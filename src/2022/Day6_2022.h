#pragma once
#include "IDay.h"
#include <string>

class Day6_2022 : public IDay {
public:
    void PartOne();
    void PartTwo();

private:
    std::string text;

    bool IsMarker(std::string s);
};