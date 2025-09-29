#include "Day4_2023.h"
#include <iostream>
#include "Util.h"

void Day4_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day4.txt");
	int sum = 0;
	int currentCard = 0;
	cardCopies = std::vector<int>(vec.size(), 1);
	
	for (std::string& line : vec) {
		int found = 0;
		std::vector<int> winningNumbers = StringToInts<int>(line.substr(line.find(':') + 2, line.find('|') - line.find(':') - 3));
		std::vector<int> yourNumbers = StringToInts<int>(line.substr(line.find('|') + 2));
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
				cardCopies[currentTempCard] += cardCopies[currentCard];
			}
			cardCopies[currentTempCard+1] += cardCopies[currentCard];
			sum += cardAward;
		}
		currentCard++;
	}
	std::cout << "Part 1: " << sum << std::endl;

}

void Day4_2023::PartTwo()
{
	int sum = 0;
	for (const int& c : cardCopies)
		sum += c;
	std::cout << "Part 2: " << sum << std::endl;
}

