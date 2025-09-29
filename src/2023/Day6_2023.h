#pragma once
#include "IDay.h"
#include <vector>
#include <string>
#include <cmath>

class Day6_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function

    std::vector<std::string> vec;

    struct QuadraticBounds {
    public:
        QuadraticBounds(double a, double b, double c) : a(a), b(b), c(c*-1) {};
        double upper = 0.0f;
        double lower = 0.0f;

        double a = 0.0f, b = 0.0f, c = 0.0f;
        void Solve() {
            double first = (-b + sqrt(((b * b) - (4.0f * a * c)))) / (2.0f * a);
            double second = (-b - sqrt(((b * b) - (4.0f * a * c)))) / (2.0f * a);

            if (first > second){
                if(std::floor(first) == first)
                {
                    upper = first - 1;
                    lower = second + 1;
                }
                else
                {
                    upper = std::floor(first);
                    lower = std::ceil(second);
                }
            }
            else
            {
                if (std::floor(first) == first)
                {
                    upper = second - 1;
                    lower = first + 1;
                }
                else
                {
                    upper = std::floor(second);
                    lower = std::ceil(first);
                }
            }
        }
    };
};