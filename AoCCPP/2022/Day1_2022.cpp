#include "Day1_2022.h"
#include <iostream>
#include "Util.h"
#include <algorithm>


void Day1_2022::PartOne() {
    vec = GetVectorFromTxt("2022/Input/Day1.txt");
    int totCalCurrent = 0;
    for(std::string s : vec){
        if (s == ""){
            cals.push_back(totCalCurrent);
            totCalCurrent = 0;
            continue;
        }
        totCalCurrent += std::stoi(s);
    }
    int largest = 0;
    for (int i : cals) {
        if (i > largest)
            largest = i;
    }

    std::cout << "Part 1: " << largest << std::endl;
}

void Day1_2022::PartTwo() {
    std::sort(cals.begin(), cals.end(), std::greater<int>());
    std::cout << "Part 2: " << cals[0] + cals[1] + cals[2] << std::endl;
}


