#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res1 = robRange(nums, 0, nums.size()-1);
        int res2 = robRange(nums, 1, nums.size());
        return max(res1, res2);
    }
    int robRange(vector<int>& nums, int start, int end) {
        if (end - start == 1) return nums[start]; 
        vector<int> dp(end-start, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for (int i = start+2; i < end; ++i) {
            dp[i-start] = max(dp[i-1-start], dp[i-2-start] + nums[i]);
        }
        return max(dp.back(), dp[dp.size()-2]);
    }
};