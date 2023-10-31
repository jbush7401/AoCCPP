// main.cpp
#include <iostream>
#include <string>
#include <chrono>
#include "DayFactory.h"
#include "DayRegistry.h"

int main() {
    DayFactory dayFactory;
    RegisterDays(dayFactory);

    std::string year, day;
    std::cout << "Enter the Year and Day of the Problem (IE 2022 1): ";
    std::cin >> year >> day;

    IDay* instance = dayFactory.CreateInstance(year, day);
    if (instance) {
        auto start = std::chrono::high_resolution_clock::now();
        instance->PartOne();
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            elapsed).count();
        std::cout << "Part 1 Time: " << ms << std::endl;

        auto start2 = std::chrono::high_resolution_clock::now();
        instance->PartTwo();
        auto elapsed2 = std::chrono::high_resolution_clock::now() - start2;
        long long ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(
            elapsed2).count();
        std::cout << "Part 2 Time: " << ms2 << std::endl;
        std::cout << "Total time: " << ms + ms2;
        delete instance; // Don't forget to delete the instance after using it
    }
    else {
        std::cout << "Couldn't find or load the class for Year " << year << " Day " << day << ".\n";
    }

    return 0;
}