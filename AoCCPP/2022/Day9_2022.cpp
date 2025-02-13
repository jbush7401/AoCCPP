#include "Day9_2022.h"
#include "Util.h"
#include <iostream>

void Day9_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day9.txt");
	for (int x = 0; x < 2; x++)
		snake.body.push_back(Pos());
	CheckTail();
	for (std::string s : vec) {
		MoveSnakePart(s[0], std::stoi(s.substr(1)));
	}
	std::cout << "Part 1: " << snake.visited.size() << std::endl;
}

void Day9_2022::PartTwo()
{
	vec = GetVectorFromTxt("2022/Input/Day9.txt");
	snake.body.clear();
	snake.visited.clear();
	for (int x = 0; x < 10; x++)
		snake.body.push_back(Pos());
	CheckTail();
	for (std::string s : vec) {
		MoveSnakePart(s[0], std::stoi(s.substr(1)));
	}
	std::cout << "Part 2: " << snake.visited.size() << std::endl;
}


void Day9_2022::MoveSnakePart(char dir, int howMany)
{
	switch (dir) {
		case 'L':
			for (int j = 1; j <= (howMany); j++) {
				snake.body[0].x--;
				for (int i = 1; i < snake.body.size(); i++) {
					CheckPositions(i - 1, i);
				}
			}
			break;
		case 'R':
			for (int j = 1; j <= (howMany); j++) {
				snake.body[0].x++;
				for (int i = 1; i < snake.body.size(); i++) {
					CheckPositions(i - 1, i);
				}
			}
			break;
		case 'U':
			for (int j = 1; j <= (howMany); j++) {
				snake.body[0].y++;
				for (int i = 1; i < snake.body.size(); i++) {
					CheckPositions(i - 1, i);
				}
			}
			break;
		case 'D':
			for (int j = 1; j <= (howMany); j++) {
				snake.body[0].y--;
				for (int i = 1; i < snake.body.size(); i++) {
					CheckPositions(i - 1, i);
				}
			}
	}
}

void Day9_2022::CheckPositions(int posFront, int posBack) {
	int xDiff = snake.body[posBack].x - snake.body[posFront].x;
	int yDiff = snake.body[posBack].y - snake.body[posFront].y;

	if ((abs(xDiff) > 1 || abs(yDiff) > 1)) {
		if (abs(xDiff) > 0)
			snake.body[posBack].x += (-(abs(xDiff) / xDiff));
		if (abs(yDiff) > 0)
			snake.body[posBack].y += (-(abs(yDiff) / yDiff));
		if(posBack == snake.body.size()-1)
			CheckTail();
	}
}

void Day9_2022::CheckTail()
{
	for (int i = 0; i < snake.visited.size(); i++) {
		if (snake.body.back().x == snake.visited[i].x && snake.body.back().y == snake.visited[i].y)
			return;
	}
	snake.visited.push_back(Pos(snake.body.back().x, snake.body.back().y));
}
