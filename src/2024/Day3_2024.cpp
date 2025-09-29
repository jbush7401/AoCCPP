#include "Day3_2024.h"
#include "Util.h"
#include <iostream>
#include <charconv>
#include <regex>

void Day3_2024::PartOne()
{
	data = GetStringFromTxt("2024/Input/Day3.txt");

	int pos = 0;
	bool enabled = true;

	while (pos < data.size()) {
		if (data.substr(pos, 4) == "mul(") {
			pos = pos + 4;
			int num = PullNums(data.substr(pos), pos);
			part1Sum += num;
			if (enabled)
				part2Sum += num;
		}
		if (data.substr(pos, 4) == "do()")
			enabled = true;
		if (data.substr(pos, 7) == "don't()")
			enabled = false;
		pos++;
	}
	std::cout << "Part 1: " << part1Sum << std::endl;

}

void Day3_2024::PartTwo()
{
	std::cout << "Part 2: " << part2Sum << std::endl;
}

int Day3_2024::PullNums(const std::string& s, int &pos)
{
	int num1 = 0;
	int num2 = 0;
	const char* str = s.c_str();
	const char* end = str + s.size();

	auto [ptr, ec] = std::from_chars(str, end, num1);
	const char* cur = ptr;
	if(ptr[0] == ','){
		auto [ptr, ec] = std::from_chars(cur +1, end, num2);
		if(ptr[0] == ')'){
			if ((num1 > 0 && num1 < 1000) && (num2 > 0 && num2 < 1000)){
				pos = ptr - str + pos;
				return num1 * num2;
			}
		}
	}
	return 0; 
}

