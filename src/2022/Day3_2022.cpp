#include "Day3_2022.h"
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
	std::cout << "Part 1: " << returnSum(matches) << std::endl;
}

void Day3_2022::PartTwo()
{
	std::vector<char> matches;
	for (int i = 0; i < vec.size(); i+=3) {
		std::string s1, s2, s3;
		s1 = vec[i];
		int i2 = i + 1;
		s2 = vec[i2];
		int i3 = i + 2;
		s3 = vec[i3];

		std::vector<char> checkString = CheckForMatches(s1, s2, s3);
		matches.insert(std::end(matches), std::begin(checkString), std::end(checkString));
	}
	std::cout << "Part 2: " << returnSum(matches) << std::endl;
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
	for (char c : s1) {
		for (char d : s2) {
			if (c == d) {
				for (char e : s3) {
					if (c == e) {
						if (std::find(matches.begin(), matches.end(), c) == matches.end())
							matches.push_back(c);
					}
				}
			}
		}
	}
	
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
