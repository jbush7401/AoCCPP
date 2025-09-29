#include "Day8_2022.h"
#include "Util.h"
#include <iostream>

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
	std::cout << "Part 1: " << totalVisible << std::endl;;
}

void Day8_2022::PartTwo()
{
	int maxCount = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			int count = CountTreeVisibility(i, j);
			if (count > maxCount)
				maxCount = count;
		}
	}
	std::cout << "Part 2: " << maxCount << std::endl;;
}

bool Day8_2022::CheckTreeVisibility(int x, int y)
{
	if (x == 0 || x == grid[0].size() - 1 || y == 0 || y == grid.size() - 1)
		return true;
	//Check Up
	if (CheckUp(x, y))
		return true;
	//Check Down
	if (CheckDown(x, y))
		return true;
	//Check Left
	if (CheckLeft(x, y))
		return true;
	//Check Right
	if (CheckRight(x, y))
		return true;

	return false;
}

bool Day8_2022::CheckUp(int x, int y)
{
	int treeSize = grid[x][y];
	for (int u = x-1; u >= 0; u--)
		if (grid[u][y] >= treeSize)
			return false;
	return true;
}

bool Day8_2022::CheckDown(int x, int y)
{
	int treeSize = grid[x][y];
	for (int u = x + 1; u < grid.size(); u++)
		if (grid[u][y] >= treeSize)
			return false;
	return true;
}

bool Day8_2022::CheckLeft(int x, int y)
{
	int treeSize = grid[x][y];
	for (int u = y - 1; u >= 0; u--)
		if (grid[x][u] >= treeSize)
			return false;
	return true;
}

bool Day8_2022::CheckRight(int x, int y)
{
	int treeSize = grid[x][y];
	for (int u = y + 1; u < grid[0].size(); u++)
		if (grid[x][u] >= treeSize)
			return false;
	return true;
}

int Day8_2022::CountTreeVisibility(int x, int y)
{
	if (x == 0 || x == grid[0].size() - 1 || y == 0 || y == grid.size() - 1)
		return 0;
	return CountUp(x, y) * CountDown(x, y) * CountLeft(x, y) * CountRight(x, y);

}

int Day8_2022::CountUp(int x, int y)
{
	int count = 0;
	int treeSize = grid[x][y];
	for (int u = x - 1; u >= 0; u--)
		if (grid[u][y] < treeSize)
			count++;
		else
			return count+1;
	return count;
}

int Day8_2022::CountDown(int x, int y)
{
	int count = 0;
	int treeSize = grid[x][y];
	for (int u = x + 1; u < grid.size(); u++)
		if (grid[u][y] < treeSize)
			count++;
		else
			return count+1;
	return count;
}

int Day8_2022::CountLeft(int x, int y)
{
	int count = 0;
	int treeSize = grid[x][y];
	for (int u = y - 1; u >= 0; u--)
		if (grid[x][u] < treeSize)
			count++;
		else
			return count+1;
	return count;
}

int Day8_2022::CountRight(int x, int y)
{
	int count = 0;
	int treeSize = grid[x][y];
	for (int u = y + 1; u < grid[0].size(); u++)
		if (grid[x][u] < treeSize)
			count++;
		else
			return count+1;
	return count;
}


