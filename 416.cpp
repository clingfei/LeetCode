#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        int weight = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(weight + 1, 0));
        for (int i = nums[0]; i < weight; ++i) {              //背包的最大重量是sum/2
            dp[0][i] = nums[0];
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= weight; ++j) {
                if (j < nums[i]) dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
            }
        }
        if (dp[nums.size()-1][weight] * 2 == sum) return true;
        return false;
    }
};

class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        int weight = sum / 2;
        if (sum & 1) return false;
        
        vector<int> dp(weight+1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = weight; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp.back() * 2 == sum;
    }
};