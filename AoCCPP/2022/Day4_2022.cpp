#include "Day4_2022.h"
#include "Util.h"
#include <iostream>

void Day4_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day4.txt");
	int containedPairs = 0;
	for (std::string s : vec) {
		int i1 = std::stoi(s.substr(0, s.find_first_of('-')));
		int i2 = std::stoi(s.substr(s.find_first_of('-') + 1, (s.find_first_of(',') - s.find_first_of('-') - 1)));
		int i3 = std::stoi(s.substr(s.find_first_of(',') + 1, s.find_last_of('-') - s.find_first_of(',') - 1));
		int i4 = std::stoi(s.substr(s.find_last_of('-') + 1));
		nums.push_back(Digit(i1, i2, i3, i4));
		if((i1 >= i3 && i2 <= i4) || (i3 >= i1 && i4 <= i2))
			containedPairs++;
	}

	std::cout << "Part 1: " << containedPairs << std::endl;
}

void Day4_2022::PartTwo()
{
	int containedPairs = 0;
	for (Digit d : nums) {
		if (d.d1 >= d.d3 && d.d1 <= d.d4) {
			containedPairs++;
			continue;
		} 
		if (d.d2 >= d.d3 && d.d2 <= d.d4) {
			containedPairs++;
			continue;
		}
		if (d.d3 >= d.d1 && d.d3 <= d.d2) {
			containedPairs++;
			continue;
		}
		if (d.d4 >= d.d1 && d.d4 <= d.d2) {
			containedPairs++;
		}
	}

	std::cout << "Part 2: " << containedPairs << std::endl;
}


