#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> dp = {0, 1};
        for (int i = 2; i <= n; ++i) {
            dp.emplace_back((dp[i-1] + dp[i-2]) % int(1e9 + 7));
        }
        return dp[n];
    }
};