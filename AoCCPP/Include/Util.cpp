#include "Util.h"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>


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

std::vector<int> DelimitedToInts(const std::string& s, char delimiter)
{
    std::vector<int> strings;
    int pos = 0;
    if (s.length() == 0)
        return strings;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == delimiter) {
            std::string t = s.substr(pos, i - pos);
            trim(t);
            strings.push_back(std::stoi(t));
            pos = i + 1;
        }
        else
        {
            if (i == s.size() - 1) {
                std::string t = s.substr(pos);
                trim(t);
                strings.push_back(std::stoi(t));
            }
        }

    }
    return strings;
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


