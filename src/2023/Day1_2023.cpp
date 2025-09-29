#include "Day1_2023.h"
#include <iostream>
#include "Util.h"

void Day1_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day1.txt");
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		DocValue dv;
		dv.input = vec[i];
		dv.firstDigPos = dv.input.size();
		dv.lastDigPos = -1;
		for (int j = 0; j < dv.input.size(); j++)
			if (isdigit(dv.input[j])) {
				dv.firstDigit = dv.input[j] - '0';
				dv.firstDigPos = j;
				break;
			}
		for (int k = dv.input.size() - 1; k >= 0; k--)
			if (isdigit(dv.input[k])) {
				dv.lastDigit = dv.input[k] - '0';
				dv.lastDigPos = k;
				break;
			}
		sum += dv.firstDigit * 10 + dv.lastDigit;
		docValues.push_back(dv);
	}
	std::cout << "Part 1: " << sum << std::endl;
}

void Day1_2023::PartTwo()
{
	int sum = 0;
	for(int i = 0; i < docValues.size(); i++){
		for (int j = 0; j < 9; j++) {
			int whereIsDigit = docValues[i].input.find(digits[j]);
			if (whereIsDigit < 0)
				continue;
			if (whereIsDigit < docValues[i].firstDigPos)
			{
				docValues[i].firstDigPos = whereIsDigit;
				docValues[i].firstDigit = j + 1;
			}
			whereIsDigit = docValues[i].input.rfind(digits[j]);
			if (whereIsDigit > docValues[i].lastDigPos) {
				docValues[i].lastDigPos = whereIsDigit;
				docValues[i].lastDigit = j + 1;
			}
		}
		sum += docValues[i].firstDigit * 10 + docValues[i].lastDigit;
	}

	std::cout << "Part 2: " << sum << std::endl;
}




