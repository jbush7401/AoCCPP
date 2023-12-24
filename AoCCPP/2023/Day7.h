#pragma once
#include "IDay.h"
#include <vector>
#include <string>
#include <unordered_set>

class Day7_2023 : public IDay {
public:
    void PartOne(); // declaration of PartOne function
    void PartTwo(); // declaration of PartTwo function

    std::vector<std::string> vec;
    
    const enum HandRank { HighCard, OnePair, TwoPair, ThreeOfAKind, FullHouse, FourOfAKind, FiveOfAKind };

    class Hand {
    public:
        std::string originalHand = "";
     
        HandRank handStr = HighCard;
        int rank = 0;

        static bool CompareHands(const Day7_2023::Hand& h1, const Day7_2023::Hand& h2, const std::string& cards)
        {
           
            if (h1.handStr == h2.handStr) {
                for (int i = 0; i < 5; i++) {
                    int h1Rank = cards.find_first_of(h1.originalHand[i]);
                    int h2Rank = cards.find_first_of(h2.originalHand[i]);
                    if (h1Rank == h2Rank)
                        continue;
                    return h1Rank < h2Rank;
                }
            }
            return h1.handStr < h2.handStr;
        }
    };

    HandRank FindRank(Hand& h);
    std::vector<Hand> hands = {};

private:
    
    

   

   

    

};