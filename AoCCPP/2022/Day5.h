#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day5_2022 : public IDay {
public:
    void PartOne(); 
    void PartTwo(); 

private:
    std::vector<std::string> vec;

    void FindStackCount(std::vector<std::string>& vec);
};