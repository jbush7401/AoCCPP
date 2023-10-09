// main.cpp
#include <iostream>
#include <string>
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
        instance->PartOne();
        instance->PartTwo();
        delete instance; // Don't forget to delete the instance after using it
    }
    else {
        std::cout << "Couldn't find or load the class for Year " << year << " Day " << day << ".\n";
    }

    return 0;
}