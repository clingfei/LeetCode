#include <vector>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        long long res = 0;
        vector<vector<long long>> dp(5, vector<long long>(n, 0));
        for (int i = 0; i < 5; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < n; ++j) {
            for(int i = 0; i < 5; ++i) {
                switch(i) {
                    case 0: dp[i][j] = (dp[1][j-1] + dp[2][j-1] + dp[4][j-1]) % (int(pow(10, 9) + 7)); break;
                    case 1: dp[i][j] = (dp[0][j-1] + dp[2][j-1])% (int(pow(10, 9) + 7)); break;
                    case 2: dp[i][j] = (dp[1][j-1] + dp[3][j-1]) % (int(pow(10, 9) + 7)); break;
                    case 3: dp[i][j] = dp[2][j-1] % (int(pow(10, 9) + 7)); break;
                    case 4: dp[i][j] = (dp[3][j-1] + dp[2][j-1]) % (int(pow(10, 9) + 7)); break;
                }
            } 
        }
        for (int i = 0; i < 5; ++i) {
            res = (res + dp[i].back()) % (int(pow(10, 9) + 7));
        }
        return res;
    }
};