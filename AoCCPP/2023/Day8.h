#pragma once
#include "IDay.h"
#include <vector>
#include <string>
#include <unordered_map>

class Day8_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function

    std::vector<std::string> vec;

    std::string instructions;

    struct Node {
        Node(std::string l = "", std::string r = "") : left(l), right(r) {};
        std::string left;
        std::string right;
    };

    std::unordered_map<std::string, Node> dict;

    std::vector<Node> part2Starts;
};