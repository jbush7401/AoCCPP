#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day1_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function
    std::vector<std::string> vec;

    struct DocValue {
    public:
        DocValue(std::string i = "", int fdp = 0, int ldp = 0, int fd = 0, int ld = 0) : input(i), firstDigPos(fdp), lastDigPos(ldp), firstDigit(fd), lastDigit(ld) {};
    
        std::string input = "";
        int firstDigPos = 0;
        int lastDigPos = 0;
        int firstDigit = 0;
        int lastDigit = 0;
    };

    std::string digits[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    std::vector<DocValue> docValues;
};