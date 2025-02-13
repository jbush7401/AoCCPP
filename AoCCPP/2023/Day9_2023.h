#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day9_2023 : public IDay {
public:
	void PartOne();
	void PartTwo();

	std::vector<std::string> vec;

	std::vector<std::vector<int>> histories;

	int processHistory(std::vector<std::vector<int>> &h);
};