#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if (hand.size() % groupSize != 0) 
            return false;
        sort(hand.begin(), hand.end());
        map<int, int> mmap;
        for (int i=0; i < hand.size(); ++i) {
            mmap[hand[i]]++;
        }               //统计每个数字出现的次数
        for (int i = 0; i < hand.size(); ++i) {
            if (mmap[hand[i]] == 0) continue;
            mmap[hand[i]]--;
            for (int j = 1; j < groupSize; ++j) {
                if (mmap[hand[i] + j] == 0)
                    return false;
                else 
                    mmap[hand[i] + j] --; 
            }
        }
        return true;
    }
}; 