#include "Day5_2022.h"
#include "Util.h"
#include <iostream>

void Day5_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day5.txt");
	
	FindStackCount();
	for (int i = 0; i < ColumnCount; i++)
		stacks.push_back(std::stack<char>());
	
	// Load the vector of stacks with original data
	for(int row = LastStackRow; row >= 0; row--)
		for (int col = 0; col < ColumnCount; col++) {
			if(vec[row][col * 4 + 1] != ' ')
				stacks[col].push(vec[row][col * 4 + 1]);
		}

	stacksOriginal = stacks;
	// Process Move Commands
	for (int i = LastStackRow + 3; i < vec.size(); i++) {
		size_t fpos = vec[i].find_first_of('e');
		size_t spos = vec[i].find_first_of('f');
		size_t howMany = stoi(vec[i].substr(fpos + 2, spos - fpos - 3));
		fpos = vec[i].find("from");
		spos = vec[i].find_first_of('t');
		int from = stoi(vec[i].substr(fpos + 5, spos - fpos - 6));
		fpos = vec[i].find("to");
		int to = stoi(vec[i].substr(fpos + 3));
		commands.push_back(Command(howMany, from, to));
	}

	for (Command& c : commands) {
		for (int i = 0; i < c.howMany; i++) {
			char box = stacks[c.from - 1].top();
			stacks[c.from - 1].pop();
			stacks[c.to - 1].push(box);
		}
	}
	
	std::cout << "Part 1: " << PrintAnswer(stacks) << std::endl;
}

void Day5_2022::PartTwo()
{
	for (Command& c : commands) {
		std::stack<char> tempStack;

		for (int i = 0; i < c.howMany; i++) {
			tempStack.push(stacksOriginal[c.from - 1].top());
			stacksOriginal[c.from - 1].pop();
		}
		while(tempStack.size() > 0) {
			stacksOriginal[c.to - 1].push(tempStack.top());
			tempStack.pop();
		}
	}

	std::cout << "Part 2: " << PrintAnswer(stacksOriginal) << std::endl;
	
}

void Day5_2022::FindStackCount()
{
	for (int i = 0; i < vec.size(); i++)
		if (vec[i].length() > 0 && isdigit(vec[i][1])) {
			ColumnCount = vec[i][vec[i].length() - 2] - '0';
			LastStackRow = i - 1;
			return;
		}
}

std::string Day5_2022::PrintAnswer(std::vector<std::stack<char>>& boxes)
{
	std::string answer;
	for (std::stack<char> s : boxes) {
		answer += s.top();
	}
	return answer;
}




