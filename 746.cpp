#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.emplace_back(cost[0]);
        dp.emplace_back(cost[1]);
        if (cost.size() == 2) return 0;
        for (int i = 2; i < cost.size(); ++i) {
            dp.emplace_back(min(dp[i-2] + cost[i-2], dp[i-1]+cost[i-1]));
        }
        return dp.back();

    }
};