#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day2_2024 : public IDay {
	int part1Sum = 0;
	int part2Sum = 0;
	
	void PartOne();
	void PartTwo();

	std::vector<std::vector<int>> data;

	bool processSafe(const std::vector<int>& nums);
	bool NumCheck(bool (*func)(int, int), int x, int y);
	std::vector<int> removeAtIndex(int index, const std::vector<int> &nums);
};
