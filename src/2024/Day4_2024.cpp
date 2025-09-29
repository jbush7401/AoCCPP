#include "Day4_2024.h"
#include "Util.h"
#include <iostream>

bool PartTwoMatch(std::string s) {
	return s == "MS" || s == "SM";
}

void Day4_2024::PartOne()
{
	input = Get2dVectorMatrixFromTxt("2024/Input/Day4.txt");
	for (int y = 0; y < input.size(); y++) {
		for (int x = 0; x < input[0].size(); x++) {
			if (input[y][x] == 'X') {
				partOneFound += CheckForWordPartOne(x, y);
			}
			if (input[y][x] == 'A') {
				partTwoFound += CheckForWordPartTwo(x, y);
			}
		}
	}
	std::cout << "Part 1: " << partOneFound << std::endl;
}

void Day4_2024::PartTwo()
{
	std::cout << "Part 2: " << partTwoFound << std::endl;
}

int Day4_2024::CheckForWordPartOne(int x, int y)
{
	int found = 0;
	// Check Up
	if (y > 2){
		if (input[y - 1][x] == 'M' && input[y - 2][x] == 'A' && input[y - 3][x] == 'S')
			found++;
		if(x < input[0].size() - 3)
			if (input[y - 1][x+1] == 'M' && input[y - 2][x+2] == 'A' && input[y - 3][x+3] == 'S')
				found++;
	}
	// Check Right
	if (x < input[0].size() - 3){
		if (input[y][x+1] == 'M' && input[y][x+2] == 'A' && input[y][x+3] == 'S')
			found++;
		if (y < input.size() - 3)
			if (input[y + 1][x + 1] == 'M' && input[y + 2][x + 2] == 'A' && input[y + 3][x + 3] == 'S')
				found++;
	}
	// Check Down
	if(y < input.size() - 3){
		if (input[y + 1][x] == 'M' && input[y + 2][x] == 'A' && input[y + 3][x] == 'S')
			found++;
		if (x > 2)
			if (input[y + 1][x - 1] == 'M' && input[y + 2][x - 2] == 'A' && input[y + 3][x - 3] == 'S')
				found++;
	}
	// Check Left
	if (x > 2){
		if (input[y][x - 1] == 'M' && input[y][x - 2] == 'A' && input[y][x - 3] == 'S')
			found++;
		if (y > 2)
			if (input[y - 1][x - 1] == 'M' && input[y - 2][x - 2] == 'A' && input[y - 3][x - 3] == 'S')
				found++;
	}
		
	return found;
}

int Day4_2024::CheckForWordPartTwo(int x, int y)
{
	int found = 0;
	if(y+1 < input.size() && y-1 >= 0 && x+1 < input[0].size() && x-1 >= 0)
		if (PartTwoMatch({ input[y + 1][x - 1], input[y - 1][x + 1] }) && PartTwoMatch({ input[y-1][x-1], input[y+1][x+1]}))
			found++;
	return found;
}


