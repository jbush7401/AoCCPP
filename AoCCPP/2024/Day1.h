#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day1_2024 : public IDay {
public:
	void PartOne();
	void PartTwo();

	std::vector<int> list1;
	std::vector<int> list2;
};
