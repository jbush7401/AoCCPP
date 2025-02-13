#include "Day2_2022.h"
#include "Util.h"
#include <iostream>

void Day2_2022::PartOne()
{
	int total = 0;
	vec = GetVectorFromTxt("2022/Input/Day2.txt");

	for (std::string s : vec) {
		rps player, opponent;
		//Get player and opponent char
		switch (s[0]) {
			case 'A':
				opponent = rock;
				break;
			case 'B':
				opponent = paper;
				break;
			default:
				opponent = scissors;
				break;
		}
		switch (s[2]) {
			case 'X':
				player = rock;
				break;
			case 'Y':
				player = paper;
				break;
			default:
				player = scissors;
				break;
		
		}
		total += ScoreResults(player, opponent);
	}
	std::cout << "Part 1: " << total << std::endl;
}

void Day2_2022::PartTwo()
{
	int total = 0;
	for (std::string s : vec) {
		rps player, opponent;
		switch (s[0]) {
		case 'A':
			opponent = rock;
			break;
		case 'B':
			opponent = paper;
			break;
		default:
			opponent = scissors;
			break;
		}
		switch (s[2]) {
		case 'X':
			player = WhatWins(opponent);
			break;
		case 'Y':
			player = opponent;
			break;
		default:
			player = WhatLoses(opponent);
		}
		total += ScoreResults(player, opponent);
	}
	std::cout << "Part 2: " << total << std::endl;
}

int Day2_2022::ScoreResults(rps player, rps opponent)
{
	if (player == opponent)
		return 3 + player;
	if (WhatWins(player) == opponent)
		return 6 + player;
	else
		return player;
}

Day2_2022::rps Day2_2022::WhatWins(rps player)
{
	switch (player) {
		case rock:
			return scissors;
			break;
		case scissors:
			return paper;
			break;
		default:
			return rock;
			break;

	}
}

Day2_2022::rps Day2_2022::WhatLoses(rps player)
{
	switch (player) {
	case rock:
		return paper;
		break;
	case scissors:
		return rock;
		break;
	default:
		return scissors;
		break;

	}
}

