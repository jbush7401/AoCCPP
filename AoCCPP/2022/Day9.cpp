#include "Day9.h"
#include "Util.h"
#include <iostream>

void Day9_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day9.txt");
	CheckTail();
	for (std::string s : vec) {
		for (int i = 1; i <= std::stoi(s.substr(1)); i++) {
			switch (s[0]) {
				case 'L':
					head.pos.x--;
					break;
				case 'R':
					head.pos.x++;
					break;
				case 'U':
					head.pos.y++;
					break;
				case 'D':
					head.pos.y--;
					break;
			}
			CheckPositions();
		}
	}
	std::cout << "Part 1: " << tail.visited.size() << std::endl;
}

void Day9_2022::PartTwo()
{

}

void Day9_2022::CheckPositions() {
	int xDiff = tail.pos.x - head.pos.x;
	int yDiff = tail.pos.y - head.pos.y;

	if((abs(xDiff) > 1 || abs(yDiff) > 1)){
		if(abs(xDiff) > 0)
			tail.pos.x += (-(abs(xDiff) / xDiff));
		if(abs(yDiff) > 0)
			tail.pos.y += (-(abs(yDiff) / yDiff));
		CheckTail();
	}
}

void Day9_2022::CheckTail()
{
	for (int i = 0; i < tail.visited.size(); i++) {
		if (tail.pos.x == tail.visited[i].x && tail.pos.y == tail.visited[i].y)
			return;
	}
	tail.visited.push_back(Pos(tail.pos.x, tail.pos.y));
}
