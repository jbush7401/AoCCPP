#include "DayFactory.h"
#include "../2022/Day1.h"
#include "../2022/Day2.h"
#include "../2022/Day3.h"

void RegisterDays(DayFactory& dayFactory) {
	dayFactory.RegisterDay("Y2022_D1", []() { return new Day1_2022(); });
	dayFactory.RegisterDay("Y2022_D2", []() { return new Day2_2022(); });
	dayFactory.RegisterDay("Y2022_D3", []() { return new Day3_2022(); });
}
