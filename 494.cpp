#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if ((sum + target) & 1) return false;
        if (abs(target) > sum) return false;
        int weight = (target + sum) / 2;
        vector<int> dp(weight+1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = weight; j >= nums[i]; --j) {
                dp[j] += dp[j-nums[i]];
            }
        } 
        return dp.back();
    }
};