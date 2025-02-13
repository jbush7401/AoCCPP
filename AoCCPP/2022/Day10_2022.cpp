#include "Day10_2022.h"
#include "Util.h"
#include <iostream>

void Day10_2022::PartOne()
{
	vec = GetVectorFromTxt("2022/Input/Day10.txt");
	//Start cycle timer loop until end of commands
	int cycleTimer = 0;
	int currentCommandPointer = 0;
	int x = 1;
	int cycleTimerCheck = 20;
	int signalStrength = 0;
	while (cycleTimerCheck < 221) {
		if (currentCommandPointer == vec.size() - 1)
			currentCommandPointer = 0;
		//Increment Cycle Timer
		cycleTimer++;
		//Check if ready to execute next command
		
		if (currentCommand.commandType == none) {
			if (vec[currentCommandPointer].substr(0, 4) == "noop")
				currentCommand = Command(cycleTimer, noop, 0);
			else{
				currentCommand = Command(cycleTimer+1, addx, std::stoi(vec[currentCommandPointer].substr(5)));
			}
		}
		//if 20, 60, 100, 140, 180, or 220 cycle, add to total signal strength
		if (cycleTimer == cycleTimerCheck) {
			signalStrength += cycleTimerCheck * x;
			cycleTimerCheck += 40;
		}
		//Check if current command is completed and if so add to x.
		if (currentCommand.cycleEndTime == cycleTimer) {
			x += currentCommand.commandValue;
			currentCommand.commandType = none;
			currentCommandPointer++;
		}
	}
	std::cout << "Part 1: " << signalStrength << std::endl;
	
}

void Day10_2022::PartTwo()
{
	std::cout << "Part 2:" << std::endl;
	int currentCycle = 0;
	int currentCommandPointer = 0;
	int x = 1;
	int cycleTimerCheck = 39;
	int currentRow = 1;
	int currentSpriteLoc = 0;
	currentCommand = Command();
	while (currentRow <= 6) {
		if (currentCommandPointer == vec.size() - 1)
			currentCommandPointer = 0;
		//Check if ready to execute next command

		if (currentCommand.commandType == none) {
			if (vec[currentCommandPointer].substr(0, 4) == "noop")
				currentCommand = Command(currentCycle, noop, 0);
			else {
				currentCommand = Command(currentCycle + 1, addx, std::stoi(vec[currentCommandPointer].substr(5)));
			}
		}

		//Check if # or . gets printed
		if (currentSpriteLoc >= x - 1 && currentSpriteLoc <= x + 1)
			std::cout << "#";
		else
			std::cout << ".";
		
		//new line every 40
		if (currentSpriteLoc == cycleTimerCheck) {
			std::cout  << std::endl; 
			currentSpriteLoc = -1;
			currentRow++;
		}
		//Check if current command is completed and if so add to x.
		if (currentCommand.cycleEndTime == currentCycle) {
			x += currentCommand.commandValue;
			currentCommand.commandType = none;
			currentCommandPointer++;
		}
		currentCycle++;
		currentSpriteLoc++;
	}
}
