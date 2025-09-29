#pragma once
#include "IDay.h"
#include <vector>
#include <string>

class Day5_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function
    void PartTwoInefficient();

    std::vector<std::string> vec;

    struct SourceDestMap {
    public:
        SourceDestMap(long long s = 0, long long d = 0, long long v = 0) : source(s), dest(d), value(v) {};
        long long source = 0;
        long long dest = 0;
        long long value = 0;
    };

    std::vector<long long> seeds;
    std::vector<long long> seedsPart2;

    std::vector<SourceDestMap> maps[7] = {};

    long long ProcessNumber(const std::vector<SourceDestMap>& map, const long long& num);
    long long ProcessNumberBackwards(const std::vector<SourceDestMap>& map, const long long& num);
    
};