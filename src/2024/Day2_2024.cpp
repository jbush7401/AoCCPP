#include "Day2_2024.h"
#include "Util.h"
#include <iostream>

void Day2_2024::PartOne()
{
	data = GetVectorIntsFromTxt("2024/Input/Day2.txt");

	int safeTotal = 0;
	for (const std::vector<int> nums : data) {
		if(processSafe(nums))
			safeTotal++;
	}

	std::cout << "Part 1: " << safeTotal << std::endl;
}

void Day2_2024::PartTwo()
{
	int safeTotal = 0;
	for (std::vector<int> nums : data) {
		if (!processSafe(nums)) {
			for (int i = 0; i != nums.size(); i++) {
				std::vector<int> temp = removeAtIndex(i, nums);
				if (processSafe(temp)) {
					safeTotal++;
					break;
				}
			}
		}
		else
			safeTotal++;
	}
	std::cout << "Part 2: " << safeTotal << std::endl;
}

bool Day2_2024::processSafe(const std::vector<int>& nums) {
	bool (*funcPtr)(int, int) = [](int x, int y) {return x > y; };
	if (nums[0] < nums[1])
		funcPtr = [](int x, int y) {return x < y; };

	for (int i = 0; i < nums.size() - 1; i++) {
		if (!NumCheck(funcPtr, nums[i], nums[i + 1]))
		{
			return false;
		}
	}
	return true;
}

bool Day2_2024::NumCheck(bool (*func)(int, int), int x, int y) {
	return func(x, y) && (abs(x - y) <= 3);
}

std::vector<int> Day2_2024::removeAtIndex(int index, const std::vector<int> &nums)
{
	std::vector<int> temp;
	for (int i = 0; i < nums.size(); i++)
		if (i != index)
			temp.push_back(nums[i]);
	return temp;
}




