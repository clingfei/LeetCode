#include <vector>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(n, vector<double> (n * 6, 0));
        for (int i = 0; i < 6; ++i)
            dp[0][i] = 1.0 / 6.0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                for (int k = 0; k < 6 && k <= j; ++k) {
                    dp[i][j] += dp[i-1][j-k] / 6.0;
                }
            }
        }
        return vector<double>(dp.back().begin() + n - 1, dp.back().end());
    }
};