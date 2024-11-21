#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day3_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function

    std::vector<std::string> vec;

    std::vector<std::vector<char>> matrix;

    struct Pos {
    public:
        Pos(int x = 0, int y = 0) : x(x), y(y) {};
        int x = 0;
        int y = 0;
    };
    class NumberInMatrix {
    public:
        NumberInMatrix(std::string n, Pos p) : number(n), pos(p) {};
        std::string number = "";
        Pos pos;

        bool operator== (const NumberInMatrix& n1) const {
            if (this->number == n1.number && this->pos.x == n1.pos.x && this->pos.y == n1.pos.y)
                return true;
            return false;
        }
    };

    class Gear{
    public:
        Gear(Pos gl, NumberInMatrix nim) {
            gearLocation = gl;
            gearNumbers.push_back(nim);
        }
        Pos gearLocation;
        std::vector<NumberInMatrix> gearNumbers;
    };

    std::vector<NumberInMatrix> numbersInMatrix;

    std::vector<Gear> gears;

    void InsertGear(Pos loc, NumberInMatrix number);

    bool IsValidPart(const NumberInMatrix& nim);

    void InsertNumberToVec(std::string& number, Pos& pos);
};