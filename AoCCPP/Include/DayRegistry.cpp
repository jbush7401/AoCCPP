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
#include "../2023/Day3.h"
#include "../2023/Day4.h"
#include "../2023/Day5.h"
#include "../2023/Day6.h"

void RegisterDays(DayFactory& dayFactory) {
	dayFactory.RegisterDay("Y2022>_D1", []() { return std::make_unique<Day1_2022>(); });
	dayFactory.RegisterDay("Y2022>_D2", []() { return std::make_unique<Day2_2022>(); });
	dayFactory.RegisterDay("Y2022>_D3", []() { return std::make_unique<Day3_2022>(); });
	dayFactory.RegisterDay("Y2022>_D4", []() { return std::make_unique<Day4_2022>(); });
	dayFactory.RegisterDay("Y2022>_D5", []() { return std::make_unique<Day5_2022>(); });
	dayFactory.RegisterDay("Y2022>_D6", []() { return std::make_unique<Day6_2022>(); });
	dayFactory.RegisterDay("Y2022>_D7", []() { return std::make_unique<Day7_2022>(); });
	dayFactory.RegisterDay("Y2022>_D8", []() { return std::make_unique<Day8_2022>(); });
	dayFactory.RegisterDay("Y2022>_D9", []() { return std::make_unique<Day9_2022>(); });
	dayFactory.RegisterDay("Y2022>_D10", []() { return std::make_unique<Day10_2022>(); });
	dayFactory.RegisterDay("Y2023_D1", []() { return std::make_unique<Day1_2023>(); });
	dayFactory.RegisterDay("Y2023_D2", []() { return std::make_unique<Day2_2023>(); });
	dayFactory.RegisterDay("Y2023_D3", []() { return std::make_unique<Day3_2023>(); });
	dayFactory.RegisterDay("Y2023_D4", []() { return std::make_unique<Day4_2023>(); });
	dayFactory.RegisterDay("Y2023_D5", []() { return std::make_unique<Day5_2023>(); });
	dayFactory.RegisterDay("Y2023_D6", []() { return std::make_unique<Day6_2023>(); });
}
