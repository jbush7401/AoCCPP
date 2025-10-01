#include "Day1_2024.h"
#include <charconv>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>

void Day1_2024::PartOne()
{
    std::string line;
    std::ifstream myfile("2024/input/Day1.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            const char* start = line.data();
            const char* end = line.data() + line.size();
            int num1, num2;
            auto [ptr1, ec1] = std::from_chars(start, end, num1);
            auto [ptr2, ec2] = std::from_chars(ptr1 + 3, end, num2);
            list1.push_back(num1);
            list2.push_back(num2);
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