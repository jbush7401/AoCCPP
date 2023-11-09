#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>


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
