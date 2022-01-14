#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<long long int> dp = {0, 1};
        if (n <= 1) return dp[n];
        for (int i = 2; i <= n; ++i) {
            dp.emplace_back(dp[dp.size()-2] + dp[dp.size()-1]);
        }
        return dp.back();
    }
};