#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>


std::vector<std::string> GetVectorFromTxt(std::string path)
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

std::string GetStringFromTxt(std::string path)
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

std::vector<std::string> DelimitedToString(std::string s, char delimiter)
{
    std::vector<std::string> strings;
    int pos = 0;
    if (s.size() == 0)
        return strings;
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

// trim from start (in place)
static inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
        std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

