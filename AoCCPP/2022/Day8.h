#pragma once
#include "IDay.h"
#include <string>
#include <vector>

class Day8_2022 : public IDay {
public:
    void PartOne();
    void PartTwo();

private:
    std::vector<std::string> vec;
    std::vector<std::vector<int>> grid;

    bool CheckTreeVisibility(int x, int y);
    bool CheckUp(int x, int y);
    bool CheckDown(int x, int y);
    bool CheckLeft(int x, int y);
    bool CheckRight(int x, int y);

    int CountTreeVisibility(int x, int y);
    int CountUp(int x, int y);
    int CountDown(int x, int y);
    int CountLeft(int x, int y);
    int CountRight(int x, int y);


};
