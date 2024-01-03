#include "Day8.h"
#include <iostream>
#include "Util.h"

void Day8_2023::PartOne() {
	vec = GetVectorFromTxt("2023/Input/Day8.txt");

	instructions = vec[0];
	Node current;
	for (int i = 2; i < vec.size(); i++) {
		dict.insert({ vec[i].substr(0, 3) ,  Node(vec[i].substr(vec[i].find_first_of('(') + 1, 3), vec[i].substr(vec[i].find_first_of(',') + 2, 3)) });
	}
	int steps = 0;

	current = dict.at("AAA");
	bool found = false;
	while(!found){
		for (char c : instructions) {
			std::string next = "";
			if (c == 'R')
				next = current.right;
			else
				next = current.left;
			steps++;
			if (next == "ZZZ") {
				found = true;
				break;
			}
			current = dict.at(next);
		}
	}

	std::cout << "Part 1: " << steps << std::endl;
}
void Day8_2023::PartTwo() {
	for (auto n : dict) {
		if (n.first[2] == 'A') {
			part2Starts.push_back(n.second);
		}
	}
	
	long steps = 0;

	bool found = false;
	std::string next = "";
	while (!found) {
		for (char c : instructions) {
			found = true;
			for (Node& n : part2Starts) {
				if (c == 'R')
					next = n.right;
				else
					next = n.left;
				
				if (found == true && next[2] != 'Z')
					found = false;
				n = dict.at(next);
			}
			steps++;
		}
	}
	std::cout << "Part 2: " << steps << std::endl;
}