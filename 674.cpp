#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1; 
            res = max(res, dp[i]);
        }
        return res;

    }
};