#include "Day3_2023.h"
#include <iostream>
#include "Util.h"

void Day3_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day3.txt");
	bool buildingNumber = false;
	std::string number = "";
	Pos numberLoc;
	for (int i = 0; i < vec.size(); i++) {
		matrix.push_back(std::vector<char>());
		if (number != "") {
			InsertNumberToVec(number, numberLoc);
		}
		for (int j = 0; j < vec[i].size(); j++) {
			matrix[i].push_back(vec[i][j]);
			if (isdigit(vec[i][j])) {
				if (number == ""){
					numberLoc.x = j;
					numberLoc.y = i;
				}
				number += vec[i][j];
			}
			else {
				if (number != "") {
					InsertNumberToVec(number, numberLoc);
				}
			}
		}
	}
	if (number != "") {
		numbersInMatrix.push_back(NumberInMatrix(number, numberLoc));
	}

	int sum = 0;
	for (NumberInMatrix& nim : numbersInMatrix) {
		if (IsValidPart(nim)) {
			sum += std::stoi(nim.number);
		}
	}
	std::cout << "Part 1: " << sum << std::endl;
}

void Day3_2023::PartTwo()
{
	int sum = 0;
	for (Gear& g : gears) {
		if (g.gearNumbers.size() == 2)
			sum += std::stoi(g.gearNumbers[0].number) * std::stoi(g.gearNumbers[1].number);
	}
	std::cout << "Part 2: " << sum << std::endl;
}

void Day3_2023::InsertNumberToVec(std::string& number, Pos& pos)
{
	numbersInMatrix.push_back(NumberInMatrix(number, pos));
	number = "";
	pos.x = 0;
	pos.y = 0;
}

bool Day3_2023::IsValidPart(const NumberInMatrix& nim) {
	const int MAX_X = matrix[0].size();
	const int MAX_Y = matrix.size();
	bool valid = false;
	Pos locToCheck;
	for (int i = 0; i < nim.number.size(); i++) {
		locToCheck.x = nim.pos.x + i;
		locToCheck.y = nim.pos.y;
		for (int y = -1; y <= 1; y++)
			for (int x = -1; x <= 1; x++)
			{
				if ((locToCheck.x + x >= 0 && locToCheck.x + x < MAX_X) && (locToCheck.y + y >= 0 && locToCheck.y + y < MAX_Y) && !(x == 0 && y == 0)) {
					char c = matrix[locToCheck.y + y][locToCheck.x + x];
					if (matrix[locToCheck.y + y][locToCheck.x + x] != '.' && !isdigit(matrix[locToCheck.y + y][locToCheck.x + x])){
						valid = true;
						if (matrix[locToCheck.y + y][locToCheck.x + x] == '*')
							InsertGear(Pos(locToCheck.x + x, locToCheck.y + y), nim);
					}
				}
			}
	}
	return valid;;
}

void Day3_2023::InsertGear(Pos loc, NumberInMatrix number) {
	bool gearFound = false;
	bool numFound = false;
	for (Gear& gear: gears) {
		numFound = false;
		if (gear.gearLocation.x == loc.x && gear.gearLocation.y == loc.y) {
			gearFound = true;
			for (NumberInMatrix& nim: gear.gearNumbers)
				if (nim == number)
					numFound = true;
			if(!numFound)
				gear.gearNumbers.push_back(number);
		}
	}
	if (!gearFound)
		gears.push_back(Gear(loc, number));
}