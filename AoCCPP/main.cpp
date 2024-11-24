// main.cpp
#include <iostream>
#include "DayFactory.h"
#include "DayRegistry.h"
#include <DayRunner.cpp>

int main() {
    DayFactory factory;
    RegisterDays(factory);

    int year, day;
    std::cout << "Enter the Year and Day of the Problem (IE 2022 1): ";
    std::cin >> year >> day;

    if (auto instance = factory.CreateInstance(year, day)) {
        DayRunner::Run(std::move(*instance));
	}
	else {
		std::cout << "Day not found\n";
	}
	return 0;
}