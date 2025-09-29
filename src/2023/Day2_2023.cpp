#include "Day2_2023.h"
#include <iostream>
#include "Util.h"

void Day2_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day2.txt");
	const int blueMax = 14;
	const int greenMax = 13;
	const int redMax = 12;
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		int blueMin = 0, greenMin = 0, redMin = 0;
		int gameId = std::stoi(vec[i].substr(5, vec[i].find(":") - 5));
		bool validGame = true;
		std::vector<std::string> subsets = DelimitedToString(vec[i].substr(vec[i].find(":") + 2), ';');
		for (int j = 0; j < subsets.size(); j++) {
			std::vector<std::string> cubesPulled = DelimitedToString(subsets[j], ',');
			for (int k = 0; k < cubesPulled.size(); k++) {
				std::string test = cubesPulled[k].substr(cubesPulled[k].find(" ") + 1);
				int cubeCount = 0;
				if (test == "blue") {
					cubeCount = std::stoi(cubesPulled[k].substr(0, cubesPulled[k].find(" ")));
					if (cubeCount > blueMax)
						validGame = false;
					if (cubeCount > blueMin)
						blueMin = cubeCount;
				}
				else if (test == "red") {
					cubeCount = std::stoi(cubesPulled[k].substr(0, cubesPulled[k].find(" ")));
					if (cubeCount > redMax)
						validGame = false;
					if (cubeCount > redMin)
						redMin = cubeCount;
				}
				else if (test == "green") {
					cubeCount = std::stoi(cubesPulled[k].substr(0, cubesPulled[k].find(" ")));
					if (cubeCount > greenMax)
						validGame = false;
					if (cubeCount > greenMin)
						greenMin = cubeCount;
				}
			}
		}
		powerOf += blueMin * redMin * greenMin;
		if (validGame)
			sum += gameId;
	}
	std::cout << "Part 1: " << sum << std::endl;
}

void Day2_2023::PartTwo()
{
	std::cout << "Part 2: " << powerOf << std::endl;
}

