#include "Day7_2023.h"
#include <iostream>
#include "Util.h"
#include <algorithm>
#include <list>

void Day7_2023::PartOne() {
	vec = GetVectorFromTxt("2023/Input/Day7.txt");
	const std::string cards = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

	for (std::string s : vec) {
		Hand h;
		h.originalHand = s.substr(0, 5);

		h.rank = std::stoi(s.substr(6));

		hands.push_back(h);
	}

	for (int i = 0; i < hands.size(); i++) {
		//Find Hand Rank
		hands[i].handStr = FindRank(hands[i], false);
	}

	std::sort(hands.begin(), hands.end(), [&cards](const Hand& h1, const Hand& h2) {
		return Hand::CompareHands(h1, h2, cards);
		});
	
	std::cout << "Part 1: " << CalcFinal() << std::endl;
}

void Day7_2023::PartTwo() {
	const std::string cards = { 'J', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A' };

	for (int i = 0; i < hands.size(); i++) {
		//Find Hand Rank
		hands[i].handStr = FindRank(hands[i], true);
	}

	std::sort(hands.begin(), hands.end(), [&cards](const Hand& h1, const Hand& h2) {
		return Hand::CompareHands(h1, h2, cards);
		});

	std::cout << "Part 2: " << CalcFinal() << std::endl;
}

Day7_2023::HandRank Day7_2023::FindRank(Hand& h, bool part2)
{
	std::vector<size_t> solve;
	std::string charsDone = "";
	int Jokers = 0;
	for (char c : h.originalHand) {
		if (charsDone.find(c) != std::string::npos)
			continue;
		if (part2) {
			if (c == 'J'){
				Jokers++;
				continue;
			}
		}
		solve.push_back(std::count(h.originalHand.begin(), h.originalHand.end(), c));
		charsDone.push_back(c);
	}
	std::sort(solve.rbegin(), solve.rend());
	size_t FirstIndex = 0;
	if (solve.size() != 0)
		FirstIndex = solve[0];
	if (FirstIndex + Jokers == 5)
		return FiveOfAKind;
	else if (FirstIndex + Jokers == 4)
		return FourOfAKind;
	else if (FirstIndex + Jokers == 3 && solve[1] == 2)
		return FullHouse;
	else if (FirstIndex + Jokers == 3)
		return ThreeOfAKind;
	else if (FirstIndex == 2 && solve[1] == 2)
		return TwoPair;
	else if (FirstIndex + Jokers == 2)
		return OnePair;
	else
		return HighCard;
}

long Day7_2023::CalcFinal()
{
	long result = 0;
	for (int i = 1; i <= hands.size(); i++)
		result += i * hands[i - 1].rank;
	return result;
}




