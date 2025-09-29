#pragma once

#include "IDay.h"
#include <vector>
#include <string>

class Day3_2022 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function

private:
    std::vector<std::string> vec;
    std::vector<char> CheckForMatches(std::string s1, std::string s2);
    std::vector<char> CheckForMatches(std::string s1, std::string s2, std::string s3);
    int returnSum(std::vector<char> props);
};