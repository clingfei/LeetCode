#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 0) return dp;
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i >> 1] + (dp[i] & 0x01);
        }
        return dp;
    }
};