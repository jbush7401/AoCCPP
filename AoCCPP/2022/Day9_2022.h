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

    class Snake {
    public:
        std::vector<Pos> body;
        std::vector<Pos> visited;
    };

    Snake snake = Snake();

    void MoveSnakePart(char dir, int howMany);
    void CheckPositions(int posFront, int posBack);
    void CheckTail();
};