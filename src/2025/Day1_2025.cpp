#include "Day1_2025.h"
#include <string>
#include <fstream>
#include <charconv>
#include <iostream>

void Day1_2025::PartOne()
{
    std::string line;
    std::ifstream myfile("2025/Input/Day1.txt");
    if(myfile.is_open())
    {
        while (getline(myfile, line))
        {
            direction = line[0];
            auto [ptr1, ec1] = std::from_chars(line.data() + 1, line.data() + line.size(), length);
            passedZeroes += length / 100;
            length = length % 100;
            if(direction == 'L')
                length *= -1;
            dial = getDial();
            if (dial == 0){
                totalZeroes++;
                passedZeroes++;
            }
        }
    }
    std::cout << "Part 1: " << totalZeroes << std::endl;
}

void Day1_2025::PartTwo()
{
    std::cout << "Part 2: " << passedZeroes << std::endl;
}

int Day1_2025::getDial()
{
    int temp = dial + length;
    if (temp < 0){
        if(dial != 0)
            passedZeroes++;
        return 100 - abs(temp % 100);
    }
    if (temp > 100)
        if (dial != 0)
            passedZeroes++;
    return temp % 100;

    return temp;
}
