#pragma once
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
                auto end = std::chrono::high_resolution_clock::now();
                auto duration_ms = std::chrono::duration<double, std::milli>(end - start).count();
                std::cout << name << " Time: " << duration_ms << " ms\n";
                return duration_ms;
                };

            double p1Time = runPart([&]() { day.PartOne(); }, "Part 1");
            double p2Time = runPart([&]() { day.PartTwo(); }, "Part 2");
            std::cout << "Total Time: " << p1Time + p2Time << " ms\n";
        }
    };