#include "Day3.h"
#include "Util.h"

void Day3_2022::PartOne()
{
	// Load the input file into the vector
	vec = GetVectorFromTxt("2022/Input/Day3.txt");
	std::vector<char> matches;
	for (std::string s : vec) {
		std::string s1, s2;
		//split the string in two
		s1 = s.substr(0, s.length() / 2);
		s2 = s.substr(s.length() / 2, s.length()+1);
	}
}

void Day3_2022::PartTwo()
{
}

std::vector<char> CheckForMatches(std::string s1, std::string s2) {
	std::vector<char> matches;
	for (char c : s1) {
		for (char d : s2) {
			if (c == d)
				matches.push_back(c);
		}
	}
}
