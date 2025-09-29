#pragma once
#include "IDay.h"
#include "Collections.h"

class Day6_2024 : public IDay {
	void PartOne();
	void PartTwo();

	enum Direction {N, E, S, W};
	
	public:
		size_t xLength = 0, yLength = 0;

	struct Pos {
		char tile;
		bool visited = false;
		bool playerStart = false;
		Pos() : tile('.'), visited(false) {}  // Set default values
		Pos(char o, bool v, bool ps) {
			tile = o;
			visited = v;
			playerStart = ps;
		}
	};

	struct Player {
		Direction dirFacing;
		size_t currentX;
		size_t currentY;

		bool operator==(const Player& other) const {
			return dirFacing == other.dirFacing &&
				currentX == other.currentX &&
				currentY == other.currentY;
		}
	};

	struct Map {
		GenArray2d<Pos> map;
		// Default constructor
		Map() = default;

		// Use member initializer list to initialize `GenArray2d<Pos>`
		Map(size_t xM, size_t yM)
			: map(xM, yM) {
		};
	};

	bool isInBounds(const size_t& x, const size_t& y) const;
	Direction turnRight(Player& p);
	Map map;
	Player player = Player{ Direction::N, 0, 0 };
	Player playerStart = Player{ Direction::N, 0, 0 };
   
	bool IsLoop(Player p);
};