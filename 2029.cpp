#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        //alice 先手，alice选择一个被1整除的，bob选择一个被2整除的，
        if (stones.size() == 1) return false;
        vector<int>hash(3, 0);
        int cur = 0;
        for (int i = 0; i < stones.size(); ++i) {
            hash[stones[i] % 3]++;
        }
        if (hash[0] % 2 == 0) {
            if (hash[1] == 0 || hash[2] == 0)
                return false;
            else 
                return true;
        }
        else if (abs(hash[1] - hash[2]) > 2)
            return true;
            else return false;
    }
};