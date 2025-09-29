#include "Day6_2023.h"
#include <iostream>
#include "Util.h"
#include <iomanip> 

void Day6_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day6.txt");

	std::vector<int> times = StringToInts<int>(vec[0].substr(vec[0].find(':')+1));
	std::vector<int> distances = StringToInts<int>(vec[1].substr(vec[1].find(':') + 1));

	int totalWinningTimes = 1;

	for (int i = 0; i < times.size(); i++) {
		QuadraticBounds qb = QuadraticBounds(-1, times[i], distances[i]);
		qb.Solve();
		totalWinningTimes *= (int)qb.upper - (int)qb.lower + 1;
	}
	std::cout << "Part 1: " << totalWinningTimes << std::endl;

}

void Day6_2023::PartTwo()
{
	std::string strTimes = "";
	std::string strDistances = "";
	for (char c : vec[0])
		isdigit(c) ? strTimes += c : "";
	for (char c : vec[1])
		isdigit(c) ? strDistances += c : "";

	double totalWinningTimes = 1.0f;

	QuadraticBounds qb = QuadraticBounds(-1.0f, std::stod(strTimes), std::stod(strDistances));
	qb.Solve();
	totalWinningTimes *= qb.upper - qb.lower + 1;

	std::cout << "Part 2 " << std::setprecision(10) << totalWinningTimes << std::endl;
}


