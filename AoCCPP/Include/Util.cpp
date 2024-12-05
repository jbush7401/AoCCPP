#include "Util.h"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <charconv>


std::vector<std::string> GetVectorFromTxt(const std::string& path)
{
    std::string line;
    std::ifstream myfile(path);
    std::vector<std::string> vec;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vec.push_back(line);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return vec;
}

std::vector<std::vector<int>> GetVectorIntsFromTxt(const std::string& path)
{
    std::string line;
    std::ifstream myfile(path);
    std::vector<std::vector<int>> vec;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vec.push_back(DelimitedToInts(line));
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return vec;
}

std::vector<std::vector<char>> Get2dVectorMatrixFromTxt(const std::string& path) {
    std::string line;
    std::ifstream myfile(path);
    std::vector<std::vector<char>> vec;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::vector<char> l;
            for (char c : line)
                l.push_back(c);
            vec.push_back(l);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return vec;
}

char StayInIndexBounds2D(int x, int y, std::vector<std::vector<char>>& col, char failReturn) {
    if (x < 0 || y < 0)
        return failReturn;
    try {
        return col[y][x]; 
    }
    catch(...) {
        return failReturn;
    }
}

std::string GetStringFromTxt(const std::string& path)
{

    std::string line;
    std::ifstream myfile(path);
    std::string s;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            s += line;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return s;
}

std::vector<std::string> DelimitedToString(const std::string& s, char delimiter)
{
    std::vector<std::string> strings;
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delimiter){
            std::string t = s.substr(pos, i - pos);
            trim(t);
            strings.push_back(t);
            pos = i + 1;
        }
        else
        {
            if (i == s.size()-1) {
                std::string t = s.substr(pos);
                trim(t);
                strings.push_back(t);
            }
        }
       
    }
    return strings;
}

std::vector<int> DelimitedToInts(const std::string& s)
{
    std::vector<int> numbers;
    const char* str = s.c_str();
    const char* end = str + s.size();

    while (str < end) {
        // Skip leading whitespace
        while (str < end && (std::isspace(*str) || *str == ',')) ++str;
        if (str >= end) break;

        int value;
        auto [ptr, ec] = std::from_chars(str, end, value);
        if (ec == std::errc()) {
            numbers.push_back(value);
            str = ptr;
        }
        else {
            // Handle parsing error if necessary
            break;
        }
    }
    return numbers;
}

void MoveElement(std::vector<int>& vec, size_t src, size_t dst)
{
    if (src > dst) {
        std::rotate(vec.begin() + dst, vec.begin() + src, vec.begin() + src + 1);
    }
    else if (src < dst) {
        std::rotate(vec.begin() + src, vec.begin() + src + 1, vec.begin() + dst + 1);
    }
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

// trim from start (in place)
static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char ch) { return !std::isspace(ch); }));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

// Math Functions


