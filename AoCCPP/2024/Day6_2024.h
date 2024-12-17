#pragma once
#include "IDay.h"
#include <vector>

class Day6_2024 : public IDay {
	void PartOne();
	void PartTwo();

	enum Direction {N, E, S, W};

	struct Loc {
		int x, y;
		Loc(int x = 0, int y = 0) {
			this->x = x;
			this->y = y;
		}
	};
	struct Pos {
		char obstruction;
		bool visited = false;
		Loc location;
		Pos(char o, bool v, Loc l) {
			obstruction = o;
			visited = v;
			location = l;
		}
	};

	struct Player {
		Direction dirFacing;
		Loc loc;
	};

	struct Map {
		std::vector<Pos> positions;
		int xMax = 0;
		int yMax = 0;
		Map(std::vector<Pos> p, int xMax, int yMax)
	};
};