#pragma once
#include <vector>
#include <string>

std::vector<std::string> GetVectorFromTxt(const std::string& path);
std::string GetStringFromTxt(const std::string& path);
std::vector<std::string> DelimitedToString(const std::string& s, char delimiter);
std::vector<int> StringToInts(const std::string& s);
void replaceAll(std::string& str, const std::string& from, const std::string& to);
static inline void ltrim(std::string& s);
static inline void rtrim(std::string& s);
static inline void trim(std::string& s);
