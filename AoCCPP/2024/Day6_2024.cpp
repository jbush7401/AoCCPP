#include "Day6_2024.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Util.h"

void Day6_2024::PartOne()
{
    std::string line;
    std::ifstream myfile("2024/Input/Day6.txt");
    std::vector<Pos> positions;
    if (myfile.is_open())
    {
        int y = 0;
        while (getline(myfile, line) && !line.empty())
        {
            for (int x = 0; x < line.size(); x++) {
                Pos p(line[x], false, Loc(x, y));
                positions.push_back(p);
            }
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";

    std::cout << "Part 1 : ";
}

void Day6_2024::PartTwo()
{
}
