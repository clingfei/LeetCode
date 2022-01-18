#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size() + 1);
        vector<int> hash(nums.size()+1, 0);
        hash[0] = 1;
        hash[1] = 1;
        dp[0] = nums[0];
        dp[1] = nums[1];
        if (dp[0] > dp[1]) {
            dp[1] = dp[0];
            hash[1] = 0;
        }

        for (int i = 2; i < nums.size(); ++i) {
            if (hash[i-1] == 1) {
                if (dp[i-1] > dp[i-2] + nums[i]) {
                    dp[i] = dp[i-1];
                    hash[i] = 0;
                }
                else {
                    dp[i] = dp[i-2] + nums[i];
                    hash[i] = 1;
                }
            }
            else {
                dp[i] = max(dp[i-1], dp[i-2]) + nums[i];
                hash[i] = 1;
            }
        }
        return dp[nums.size()-1];
    }
};