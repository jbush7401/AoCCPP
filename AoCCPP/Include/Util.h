#pragma once
#include <vector>
#include <string>

std::vector<std::string> GetVectorFromTxt(std::string path);
std::string GetStringFromTxt(std::string path);
std::vector<std::string> DelimitedToString(std::string s, char delimiter);
static inline void ltrim(std::string& s);
static inline void rtrim(std::string& s);
static inline void trim(std::string& s);
