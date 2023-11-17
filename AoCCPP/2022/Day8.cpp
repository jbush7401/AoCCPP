#include "Day8.h"
#include "Util.h"

void Day8_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day8.txt");
	int totalVisible = 0;
	for(int i = 0; i < vec.size(); i++){
		std::vector<int> newRow;
		grid.push_back(newRow);
		for (int j = 0; j < vec[i].size(); j++) {
			int c = vec[i][j] - '0';
			grid[i].push_back(c);
		}
	}
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (CheckTreeVisibility(i, j))
				totalVisible++;
		}
	}
}

void Day8_2022::PartTwo()
{
}

bool Day8_2022::CheckTreeVisibility(int x, int y)
{
	if (x == 0 || x == grid[0].size() - 1 || y == 0 || y == grid.size() - 1)
		return true;
	//Check Up
	for(int u = x; u > 0; u--)

	//Check Down
	//Check Left
	//Check Right

	return false;
}
