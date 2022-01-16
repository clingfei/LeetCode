#include <vector>

using namespace std;

//将石头分成两堆，重量之差尽可能小

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) {
            sum += stones[i];
        }
        int weight = sum /2;
        vector<int> dp(weight + 1, 0);
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = weight; j >= stones[i]; --j) 
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
        }
        int t = sum - dp.back();
        if (dp.back() >= t)
            return dp.back() -t;
        else return t - dp.back();
    }
};