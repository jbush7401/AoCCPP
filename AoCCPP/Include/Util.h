#pragma once
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> GetVectorFromTxt(const std::string& path);
std::vector<std::vector<int>> GetVectorIntsFromTxt(const std::string& path);
std::string GetStringFromTxt(const std::string& path);
std::vector<std::string> DelimitedToString(const std::string& s, char delimiter);
std::vector<int> DelimitedToInts(const std::string& s, char delimiter);

template<typename T>
std::vector<T> StringToInts(const std::string& s)
{
    std::vector<T> result;
    std::istringstream iss(s);
    T number;

    while (iss >> number) {
        result.push_back(number);
    }

    return result;
}

void replaceAll(std::string& str, const std::string& from, const std::string& to);
static inline void ltrim(std::string& s);
static inline void rtrim(std::string& s);
static inline void trim(std::string& s);
