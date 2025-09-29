#include "Day1_2024.h"
#include "Util.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>

void Day1_2024::PartOne()
{
    std::string line;
    std::ifstream myfile("2024/input/Day1.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            size_t pos = 0;
            while (pos < line.size() && line[pos] != ' ') pos++;
            list1.push_back(std::stoi(line.substr(0, pos)));
            list2.push_back(std::stoi(line.substr(pos+1)));
        }
        myfile.close();
    }
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    long sum = 0;
    for (int i = 0; i < list1.size(); i++)
        sum += abs(list1[i] - list2[i]);

    std::cout << "Part 1: " << sum << std::endl;
}

void Day1_2024::PartTwo()
{
    long total = 0;
    for (int i : list1) {
        total += i * std::count(list2.begin(), list2.end(), i);
    }

    std::cout << "Part 2: " << total << std::endl;
}