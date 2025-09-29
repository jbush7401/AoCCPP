#include "Day5_2023.h"
#include <iostream>
#include "Util.h"

void Day5_2023::PartOne()
{
	int currentMapIndex = -1;
	vec = GetVectorFromTxt("2023/Input/Day5.txt");
	for(int i = 0; i <= 6; i++)
	
	seeds = StringToInts<long long>(vec[0].substr(vec[0].find(':') + 2));
	seedsPart2 = seeds;
	
	bool readingMaps = false;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].size() == 0) {
			currentMapIndex++;
			i += 1;
		}
		else {
			std::vector<long long> nums = StringToInts<long long>(vec[i]);
			maps[currentMapIndex].push_back(SourceDestMap(nums[1], nums[0], nums[2]));
		}
	}
	long long lowest = LONG_MAX;
	for (long long& seed : seeds) {
		for(int i = 0; i < 7; i++)
			seed = ProcessNumber(maps[i], seed);
		if (seed < lowest)
			lowest = seed;
	}
	std::cout << "Part 1: " << lowest << std::endl;
}

void Day5_2023::PartTwo()
{
	long long lowest = LLONG_MAX;
	PartTwoInefficient();
}

void Day5_2023::PartTwoInefficient() {

	long long lowest = LONG_MAX;
	long long numCheck = 0;
	for (int i = 0; i < seedsPart2.size(); i += 2) {
		for (long long j = seedsPart2[i]; j < seedsPart2[i] + seedsPart2[i + 1]; j++) {
			numCheck = j;
			for (int k = 0; k < 7; k++)
				numCheck = ProcessNumber(maps[k], numCheck);
			if (numCheck < lowest)
				lowest = numCheck;
		}
	}
	std::cout << "Part 2: " << lowest << std::endl;
}

long long Day5_2023::ProcessNumber(const std::vector<SourceDestMap>& map, const long long& num)
{
	long long destNum = num;
	for(const SourceDestMap& sdm: map)
		if (num >= sdm.source && num <= sdm.source + sdm.value - 1) {
			return num + sdm.dest - sdm.source;
		}
	return num;
}

long long Day5_2023::ProcessNumberBackwards(const std::vector<SourceDestMap>& map, const long long& num)
{
	long long destNum = num;
	for (const SourceDestMap& sdm : map)
		if (num >= sdm.source && num <= sdm.source + sdm.value - 1) {
			return num + sdm.dest - sdm.source;
		}
	return num;
	// Destination number comes in for each sdm, if >= dest && <= dest + value-1  num+source-dest
}


