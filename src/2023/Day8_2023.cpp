#include "Day8_2023.h"
#include <iostream>
#include <numeric>
#include <ranges>
#include "Util.h"

void Day8_2023::PartOne()
{
	vec = GetVectorFromTxt("2023/Input/Day8.txt");

	instructions = vec[0];
	Node current;
	for (int i = 2; i < vec.size(); i++) {
		dict.insert({ vec[i].substr(0, 3) ,  Node(vec[i].substr(vec[i].find_first_of('(') + 1, 3), vec[i].substr(vec[i].find_first_of(',') + 2, 3)) });
	}
	int steps = 0;

	auto it = dict.find("AAA");
	if (it != dict.end()) {
		current = it->second;
	}
	else
	{
		std::cout << "Key not found" << std::endl;
		return;
	}

	std::cout << "Part 1: " << GetStepsToNode("AAA", std::vector<std::string> {"ZZZ"}) << std::endl;
}
void Day8_2023::PartTwo() {
	//Get all 3 Letters that end with 'A'
	for (auto n : dict) {
		if (n.first[2] == 'A') {
			part2Starts.push_back((n.first));
		}
		if (n.first[2] == 'Z') {
			part2Finishes.push_back(n.first);
		}
	}

	// Find the first end point for each start node
	long long lcm = -1;
	std::vector<long> allSteps;

	for (const std::string &p : part2Starts) {
		if (lcm == -1)
			lcm = GetStepsToNode(p, part2Finishes);
		else
			lcm = std::lcm(GetStepsToNode(p, part2Finishes), lcm);
	}
	std::cout << "Part 2: " << lcm << std::endl;
}

long Day8_2023::GetStepsToNode(const std::string &start, const std::vector<std::string> &finish) {
	long steps = 0;
	Node current;

	auto it = dict.find(start);
	if (it != dict.end()) {
		current = it->second;
	}
	else
	{
		std::cout << "Key not found" << std::endl;
		return 0 ;
	}

	bool found = false;
	while (!found) {
		for (char c : instructions) {
			std::string next = "";
			if (c == 'R')
				next = current.right;
			else
				next = current.left;
			steps++;
			if (std::find(finish.begin(), finish.end(), next) !=  finish.end()) {
				found = true;
				break;
			}
			current = dict.at(next);
		}
	}

	return steps;
}


