#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j * j <= i; ++j) {                      
                dp[j] = max(dp[j], dp[i - j * j] + 1);
            }
        }
        return dp.back();
    }
};