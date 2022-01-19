#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]表示结尾为i-1和j-1时最多能画的线
        //如果nums[1] = nums2[j]可以加一根线，但是不能重复
        //dp[i][j] = dp[i-1][j-1] + 1如果不是,dp[i][j] = dp[]
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size(), 0));
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};