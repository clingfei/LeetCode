#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp = {1, 2};
        if (n <= 2) return dp[n-1];
        for(int i = 2; i < n; ++i) {
            dp.emplace_back(dp[dp.size()-2] + dp[dp.size()-1]);
        }
        return dp.back();
    }
};