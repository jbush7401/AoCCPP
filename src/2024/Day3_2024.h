#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day3_2024 : public IDay {
	int part1Sum = 0;
	int part2Sum = 0;

	void PartOne();
	void PartTwo();

	std::string data;

	int PullNums(const std::string &s, int& pos);
	std::vector<int> nums;
};