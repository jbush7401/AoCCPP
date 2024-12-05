#include "Day5_2024.h"
#include "Util.h"
#include <string>
#include <fstream>
#include <iostream>
#include <numeric>

void Day5_2024::PartOne()
{
	//Parse Data
    std::string line;
    std::ifstream myfile("2024/Input/Day5.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line) && !line.empty())
        {
            int n = std::stoi(line.substr(0, 2));
            protocols[n].push_back(std::stoi(line.substr(3)));
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
            bool fixed = false;
            while (!fixed)
            {
                fixed = true;
                // Iterate through each number in the update values
                for (int v = 0; v < u.values.size(); v++) {
                    // Get the protocol for the current update value
                    std::vector<int> prot = protocols[u.values[v]];
                    // Are any of the values below the current value in the update in the protocol?
                    for (int c = 0; c < v; c++)
                        if (std::find(prot.begin(), prot.end(), u.values[c]) != prot.end()) {
                            //Move values[v] to index c
                            MoveElement(u.values, v, c);
                            fixed = false;
                        }
                }
            }
        }
    }
    int sum = 0;

    for (Update i : updates) {
        sum += i.isValid ? 0 : i.values[i.values.size() / 2];
    }
    std::cout << "Part 2: " << sum << std::endl;

}
