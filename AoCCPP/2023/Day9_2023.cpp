#include "Day9_2023.h"
#include <iostream>
#include "Util.h"

void Day9_2023::PartOne()
{
	// Load each line of the input file into the 0 index of the vector of vector<int>'s
	vec = GetVectorFromTxt("2023/Input/Day9.txt");

	// Load up all the histories.
	for (const std::string &i : vec) {
		histories.push_back(DelimitedToInts(i));
	}

	// Now need to take each history and make another vector<vector<int>> for it to process it

	for (const std::vector<int>& h : histories) {
		std::vector<std::vector<int>> history_process;
		history_process.push_back(h);
		processHistory(history_process);
	}
	std::cout << "Part 1: " << "" << std::endl;
}

void Day9_2023::PartTwo()
{
}

int Day9_2023::processHistory(std::vector<std::vector<int>>& h)
{
	std::vector<int>::iterator top_history_index = h[0].end() - 1;
	// Loop until we get a end value of 0
	// Start with the top line, subtract the last two elements
	// Insert that value into the next vector of ints at the end, create the vector if it doesnt exist
	// If value is 0 then move on to getting the final value, else continue

	return 0;
}

