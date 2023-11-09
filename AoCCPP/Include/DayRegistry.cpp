#include "DayFactory.h"
#include "../2022/Day1.h"
#include "../2022/Day2.h"
#include "../2022/Day3.h"
#include "../2022/Day4.h"
#include "../2022/Day5.h"
#include "../2022/Day6.h"

void RegisterDays(DayFactory& dayFactory) {
	dayFactory.RegisterDay("Y2022_D1", []() { return new Day1_2022(); });
	dayFactory.RegisterDay("Y2022_D2", []() { return new Day2_2022(); });
	dayFactory.RegisterDay("Y2022_D3", []() { return new Day3_2022(); });
	dayFactory.RegisterDay("Y2022_D4", []() { return new Day4_2022(); });
	dayFactory.RegisterDay("Y2022_D5", []() { return new Day5_2022(); });
	dayFactory.RegisterDay("Y2022_D6", []() { return new Day6_2022(); });
}
