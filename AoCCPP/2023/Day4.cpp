#include "Day4.h"
#include <iostream>
#include "Util.h"

void Day4_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day4.txt");
	int sum = 0;
	int currentCard = 0;
	for (int i = 0; i < vec.size(); i++) {
		cardCopies.push_back(CardCopy());
	}
	for (std::string& line : vec) {
		replaceAll(line, "  ", " ");
		int found = 0;
		std::vector<int> winningNumbers = DelimitedToInt(line.substr(line.find(':') + 2, line.find('|') - line.find(':') - 3), ' ');
		std::vector<int> yourNumbers = DelimitedToInt(line.substr(line.find('|') + 2), ' ');
		for (int& winningNumber : winningNumbers) {
			for (int& yourNumber : yourNumbers) {
				if (yourNumber == winningNumber)
					found++;
			}
		}
		if (found > 0){
			int cardAward = 1;
			int currentTempCard = currentCard;
			for (int i = 1; i < found; i++){
				cardAward *= 2;
				currentTempCard++;
				for (int i = 1; i <= cardCopies[currentCard].copies; i++)
					cardCopies[currentTempCard].copies++;
			}
			for (int i = 1; i <= cardCopies[currentCard].copies; i++)
				cardCopies[currentTempCard+1].copies++;
			sum += cardAward;
		}
		currentCard++;
	}
	std::cout << "Part 1: " << sum << std::endl;

}

void Day4_2023::PartTwo()
{
	int sum = 0;
	for (const CardCopy& c : cardCopies)
		sum += c.copies;
	std::cout << "Part 2: " << sum << std::endl;
}

