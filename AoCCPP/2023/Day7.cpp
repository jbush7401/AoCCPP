#include "Day7.h"
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
		hands[i].handStr = FindRank(hands[i]);
	}

	std::sort(hands.begin(), hands.end(), [&cards](const Hand& h1, const Hand& h2) {
		return Hand::CompareHands(h1, h2, cards);
		});
	long result = 0;
	for (int i = 1; i <= hands.size(); i++)
		result += i * hands[i - 1].rank;
	std::cout << "Part 1: " << result << std::endl;
}

void Day7_2023::PartTwo() {
}

Day7_2023::HandRank Day7_2023::FindRank(Hand& h)
{
	std::vector<int> solve;
	std::string charsDone = "";
	for (char c : h.originalHand) {
		if (charsDone.find(c) != std::string::npos)
			continue;
		solve.push_back(std::count(h.originalHand.begin(), h.originalHand.end(), c));
		charsDone.push_back(c);
	}
	std::sort(solve.rbegin(), solve.rend());
	if (solve.size() == 1)
		return FiveOfAKind;
	else if (solve[0] == 4)
		return FourOfAKind;
	else if (solve[0] == 3 && solve[1] == 2)
		return FullHouse;
	else if (solve[0] == 3)
		return ThreeOfAKind;
	else if (solve[0] == 2 && solve[1] == 2)
		return TwoPair;
	else if (solve[0] == 2)
		return OnePair;
	else
		return HighCard;
}




