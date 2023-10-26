#include "Day3.h"
#include "Util.h"
#include <iostream>

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
		std::vector<char> checkString = CheckForMatches(s1, s2);
		matches.insert(std::end(matches), std::begin(checkString), std::end(checkString));
	}
	std::cout << "Part 2: " << returnSum(matches);
}

void Day3_2022::PartTwo()
{

}

std::vector<char> Day3_2022::CheckForMatches(std::string s1, std::string s2) {
	std::vector<char> matches;
	for (char c : s1) {
		for (char d : s2) {
			if (c == d){
				if (std::find(matches.begin(), matches.end(), c) == matches.end())
					matches.push_back(c);
			}
		}
	}
	return matches;
}

std::vector<char> Day3_2022::CheckForMatches(std::string s1, std::string s2, std::string s3)
{
	std::vector<char> matches;
	return matches;
}

int Day3_2022::returnSum(std::vector<char> props)
{
	int sum = 0;
	for (char c : props) {
		if (islower(c))
			sum += c - 96;
		else
			sum += c - 38;
	}
	return sum;
}
