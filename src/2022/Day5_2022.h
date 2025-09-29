#pragma once
#include "IDay.h"
#include <vector>
#include <string>
#include <stack>

class Day5_2022 : public IDay {
public:
    void PartOne(); 
    void PartTwo(); 

private:
    struct Command {
        size_t howMany, from, to;
        Command(size_t hm, int f, int t) : howMany(hm), from(f), to(t) {};
    };
    std::vector<std::string> vec;
    std::vector<std::stack<char>> stacks;
    std::vector<std::stack<char>> stacksOriginal;
    std::vector<Command> commands;
    int ColumnCount = 0;
    int LastStackRow = 0;

    void FindStackCount();
    std::string PrintAnswer(std::vector<std::stack<char>>&);
};