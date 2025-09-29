#pragma once
#include "IDay.h"
#include <vector>
#include <string>
#include <cstdint>

class Day1_2024 : public IDay {
public:
	void PartOne();
	void PartTwo();

	std::vector<int32_t> list1;
	std::vector<int32_t> list2;
};
