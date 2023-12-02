#include "DayFactory.h"
#include "../2022/Day1.h"
#include "../2022/Day2.h"
#include "../2022/Day3.h"
#include "../2022/Day4.h"
#include "../2022/Day5.h"
#include "../2022/Day6.h"
#include "../2022/Day7.h"
#include "../2022/Day8.h"
#include "../2022/Day9.h"
#include "../2022/Day10.h"
#include "../2023/Day1.h"
#include "../2023/Day2.h"

void RegisterDays(DayFactory& dayFactory) {
	dayFactory.RegisterDay("Y2022_D1", []() { return new Day1_2022(); });
	dayFactory.RegisterDay("Y2022_D2", []() { return new Day2_2022(); });
	dayFactory.RegisterDay("Y2022_D3", []() { return new Day3_2022(); });
	dayFactory.RegisterDay("Y2022_D4", []() { return new Day4_2022(); });
	dayFactory.RegisterDay("Y2022_D5", []() { return new Day5_2022(); });
	dayFactory.RegisterDay("Y2022_D6", []() { return new Day6_2022(); });
	dayFactory.RegisterDay("Y2022_D7", []() { return new Day7_2022(); });
	dayFactory.RegisterDay("Y2022_D8", []() { return new Day8_2022(); });
	dayFactory.RegisterDay("Y2022_D9", []() { return new Day9_2022(); });
	dayFactory.RegisterDay("Y2022_D10", []() { return new Day10_2022(); });
	dayFactory.RegisterDay("Y2023_D1", []() { return new Day1_2023(); });
	dayFactory.RegisterDay("Y2023_D2", []() { return new Day2_2023(); });
}
