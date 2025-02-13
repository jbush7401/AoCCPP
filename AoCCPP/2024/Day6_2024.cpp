#include "Day6_2024.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Util.h"

void Day6_2024::PartOne()
{
    std::string line;
    std::ifstream myfile("2024/Input/Day6.txt");
   
    std::string firstLine;
    std::vector<Pos> pss;
    size_t x = 0, y = 0;
    while (getline(myfile, line) && !line.empty()) {
        if (yLength == 0) {
            xLength = line.size(); // Capture length of the first line
        }
        for (char c : line)
        {
            bool playerStart = false;
            if (c == '^')
            {
                player.currentX = x;
                player.currentY = y;
                player.dirFacing = N;
                c = '.';
                playerStart = true;
            }
            pss.push_back(Pos(c, false, playerStart));
            
            ++x;
        }
        ++yLength;
        ++y;
        x = 0;
    }
    playerStart = player;
    Map m(xLength, yLength);
    m.map.set(pss);
    bool inBounds = true;
    Pos* ahead;
    while (inBounds) {
        // Check direction facing and see what is in front
        size_t x = player.currentX, y = player.currentY;
        switch (player.dirFacing) {
            case N:
                y--;
                break;
            case S:
                y++;
                break;
            case E:
                x++;
                break;
            case W:
                x--;
                break;
        }

        if (isInBounds(x, y)) {
            ahead = m.map.get(x, y);
            if (ahead->tile == '.'){
                m.map.set(player.currentX, player.currentY, Pos('.', true, false));
                player.currentX = x;
                player.currentY = y;
            }
            else if (ahead->tile == '#')
                turnRight(player);
        }
        else {
            inBounds = false;
            m.map.set(player.currentX, player.currentY, Pos('.', true, false));
        }
    }
    int totalVisited = 0;
    for (int i = 0; i < m.map.getSize(); i++) {
        if (m.map.get(i)->visited == true)
            totalVisited++;
    }
    map = m;

    std::cout << "Part 1 : " << totalVisited << std::endl;
}

void Day6_2024::PartTwo()
{
    int loops = 0;
    //Iterate through solution player positions from part 1
    // Each needs to update the map with a # at the position
    // Start the player off and see if infinite loop
    Pos* current;
    for (int i = 0; i < map.map.getSize() ;i ++) {
        current = map.map.get(i);
        if (map.map.get(i)->visited == true) {
            if (current->playerStart == false) {
                current->tile = '#';
            }
            if (IsLoop(playerStart) == true)
                loops++;
            current->tile = '.';
        }
    }
    std::cout << "Part 2 : " << loops << std::endl;
}

bool Day6_2024::isInBounds(const size_t &x, const size_t &y) const
{
    if (x >= 0 && x < xLength && y >= 0 && y < yLength)
        return true;

     return false;
}

Day6_2024::Direction Day6_2024::turnRight(Player& p)
{
    switch (p.dirFacing) {
    case N:
        p.dirFacing = E;
        break;
    case E:
        p.dirFacing = S;
        break;
    case S:
        p.dirFacing = W;
        break;
    case W:
        p.dirFacing = N;
        break;
    }
    return p.dirFacing;
}

bool Day6_2024::IsLoop(Player player)
{
    std::vector<Player> pastPlayers;
    bool inBounds = true;
    Pos* ahead;
    while (inBounds) {
        // Check direction facing and see what is in front
        size_t x = player.currentX, y = player.currentY;
        switch (player.dirFacing) {
        case N:
            y--;
            break;
        case S:
            y++;
            break;
        case E:
            x++;
            break;
        case W:
            x--;
            break;
        }

        if (isInBounds(x, y)) {
            ahead = map.map.get(x, y);
            if (ahead->tile == '.') {
                player.currentX = x;
                player.currentY = y;
            }
            else if (ahead->tile == '#'){
                for (const Player& p : pastPlayers) {
                    if (p == player)
                        return true;
                }
                pastPlayers.push_back(player);
                turnRight(player);
            }
        }
        else
            inBounds = false;
    }
    return false;
}
