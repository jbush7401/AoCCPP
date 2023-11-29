#pragma once
#include "IDay.h"
#include <string>
#include <vector>

class Day10_2022 : public IDay {
public:
    void PartOne();
    void PartTwo();

protected:
    std::vector<std::string> vec;
    enum CommandType {
        none,
        noop,
        addx
    };
    struct Command {
        Command(int cs = 0, CommandType ct = none, int cv = 0) : cycleStarted(cs), commandType(ct), commandValue(cv) {};
        int cycleStarted;
        CommandType commandType;
        int commandValue = 0;
    };

    Command currentCommand;
};
