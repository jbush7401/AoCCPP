#pragma once

#include "IDay.h"
#include <vector>
#include <string>
#include <map>

class Day2_2022 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function
    
private: 
    std::vector<std::string> vec;
    enum rps { rock = 1, paper = 2, scissors = 3};
    int ScoreResults(rps player, rps opponent);
    rps WhatWins(rps player);
    rps WhatLoses(rps player);

};
