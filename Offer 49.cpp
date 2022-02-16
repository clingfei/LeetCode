#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 1);
        int p1 = 1, p2 = 1, p3 = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = min(dp[p1] * 2, min(dp[p2] * 3, dp[p3] * 5));
            dp[i] = temp;
            if (temp == dp[p1] * 2)
                p1++;
            if (temp == dp[p2] * 3)
                p2++;
            if (temp == dp[p3] * 5)
                p3++; 
        }
        return dp.back();
    }
};