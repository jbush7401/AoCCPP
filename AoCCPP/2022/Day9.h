#pragma once
#include "IDay.h"
#include <string>
#include <vector>

class Day9_2022 : public IDay {
public:
    void PartOne();
    void PartTwo();

private:
    std::vector<std::string> vec;
    struct Pos {
        Pos(int x = 0, int y = 0) : x(x), y(y) {};
        int x;
        int y;
    };

    class Head {
    public:
        Pos pos;
        Head(Pos p = Pos()) : pos(p) {};
    };

    class Tail {
    public:
        Pos pos;
        Tail(Pos p = Pos()) : pos(p) {};
        std::vector<Pos> visited;
    };

    class Snake {
    public:
        Pos array[9];
        std::vector<Pos> visited;
    };

    Head head = Head();
    Tail tail = Tail();

    void CheckPositions();
    void CheckTail();
};