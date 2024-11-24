#pragma once
#include <memory>
#include <chrono>
#include <iostream>
#include "IDay.h"

class DayRunner {
public:
	template<typename T>
	static void Run(T&& day) {
		auto runPart = [](auto&& part, const char* name) {
			auto start = std::chrono::high_resolution_clock::now();
			part();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();
			std::cout << name << " Time: " << duration << "ms\n";
			return duration;
			};

		auto p1Time = runPart([&]() { day.PartOne(); }, "Part 1");
		auto p2Time = runPart([&]() { day.PartTwo(); }, "Part 2");
		std::cout << "Total time: " << p1Time + p2Time << "ms\n";
	}
};