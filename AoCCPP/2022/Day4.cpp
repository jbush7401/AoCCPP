#include "Day4.h"
#include "Util.h"
#include <iostream>

void Day4_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day4.txt");
	for (std::string s : vec) {
		std::string i1 = s.substr(0, s.find_first_of('-'));
		std::string i2 = s.substr(s.find_first_of('-') + 1, (s.find_first_of(',') - s.find_first_of('-')-1));
	}
}

void Day4_2022::PartTwo()
{
}
