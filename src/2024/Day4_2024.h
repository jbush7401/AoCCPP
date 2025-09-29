#pragma once
#include "IDay.h"
#include <vector>

class Day4_2024 : public IDay {
	int partOneFound = 0;
	int partTwoFound = 0;
	
	void PartOne();
	void PartTwo();

	int CheckForWordPartOne(int x, int y);
	int CheckForWordPartTwo(int x, int y);

	std::vector<std::vector<char>> input;

};