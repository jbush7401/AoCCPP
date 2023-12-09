#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day7_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function
private:
    std::vector<std::string> vec;

    enum Card {A, F2, F3, F4, F5, F6, F7, F8, F9, J, Q, K };

    class Hand {
        std::string originalHand = "";
        Card hand[5];
    };

};