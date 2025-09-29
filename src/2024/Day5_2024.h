#pragma once
#include "IDay.h"
#include <vector>
#include <unordered_map>

class Day5_2024 : public IDay {
	void PartOne();
	void PartTwo();

	struct Update {
		std::vector<int> values;
		bool isValid = true;
	};

	std::unordered_map<int, std::vector<int>> protocols;
	std::vector<Update> updates;
};