#include "Day6_2022.h"
#include "Util.h"
#include <algorithm>
#include <iostream>

void Day6_2022::PartOne()
{
	text = GetStringFromTxt("2022/Input/Day6.txt");

	for (int i = 3; i < text.length(); i++) {
		std::string s = std::string() + text[i - 3] + text[i - 2] + text[i - 1] + text[i];
		if (IsMarker(s)){
			std::cout << "Part 1: " << i+1 << std::endl;
			return;
		}
	}
}

void Day6_2022::PartTwo()
{
	for (int i = 13; i < text.length(); i++) {
		std::string s = std::string() + text.substr(i-13, 14);
		if (IsMarker(s)) {
			std::cout << "Part 2: " << i + 1 << std::endl;
			return;
		}
	}
}

bool Day6_2022::IsMarker(std::string s)
{
	int count = 0;
	for (char c : s) {
		
		for (char k : s) {
			if (c == k)
				count++;
		}
		if (count > 1)
			return false;
		count = 0;
	}
	return true;
}

