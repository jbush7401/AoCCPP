#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day4_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function

    std::vector<std::string> vec;

    struct CardCopy {
    public:
        int copies = 1;
    };
    std::vector<int> cardCopies;
};