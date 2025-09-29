#include "Day5_2024.h"
#include "Util.h"
#include <string>
#include <fstream>
#include <iostream>
#include <numeric>
#include <algorithm>

void Day5_2024::PartOne()
{
	//Parse Data
    std::string line;
    std::ifstream myfile("2024/Input/Day5.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line) && !line.empty())
        {
            protocols[std::stoi(line.substr(0, 2))].push_back(std::stoi(line.substr(3)));
        }
        while (getline(myfile, line)) {
            Update u;
            u.values = DelimitedToInts(line);
            updates.push_back(u);
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";

    // Check each rule
    // For each number check to make sure it is before the numbers it should be for each update, add to false list if not.
    for (const auto& pair : protocols) { 
        for (Update &update : updates) {
            if(update.isValid){
                // Check if this protoctal first is in the current update
                auto it = std::find(update.values.begin(), update.values.end(), pair.first);
                if (it != update.values.end()) {
                    // It is in the update, now check each number before the first if it is in pair.second
                    for (int i = 0; i < std::distance(update.values.begin(), it); i++) {
                        if (std::find(pair.second.begin(), pair.second.end(), update.values[i]) != pair.second.end())
                        {
                            update.isValid = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for (Update i : updates) {
        sum += i.isValid ? i.values[i.values.size() / 2] : 0;
    }

     std::cout << "Part 1: " << sum << std::endl;

}

void Day5_2024::PartTwo()
{
    // Iterate through the bad updates
    for (Update& u : updates) {
        if (!u.isValid)
        {
            std::sort(u.values.begin(), u.values.end());
            std::vector<int> newOrder = u.values;

            // Iterate through this updates values, check each prop how many of the other update values should be in front of this one.
            for (int i = 0; i < u.values.size(); i++) {
                int val = u.values[i];
                std::vector<int> prot = protocols[val]; 
                std::vector<int> common;
                std::sort(prot.begin(), prot.end());
                std::set_intersection(u.values.begin(), u.values.end(), prot.begin(), prot.end(), std::back_inserter(common));
                newOrder[newOrder.size() - common.size() - 1] = val;
            }
            u.values = newOrder;
        }
    }
    int sum = 0;

    for (Update i : updates) {
        sum += i.isValid ? 0 : i.values[i.values.size() / 2];
    }
    std::cout << "Part 2: " << sum << std::endl;

}

