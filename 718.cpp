#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, 0));
        int res = 0;
        //dp[i][j]表示以下标i-1为结尾的A， 以j-1为结尾的B，最大的长度
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > res) 
                    res = dp[i][j];
            }
        }
        return res;
    }
};