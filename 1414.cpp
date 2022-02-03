#include <vector>

using namespace std;
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 1) return 1;
        vector<int> dp;
        dp.emplace_back(0);
        dp.emplace_back(1);
        while (dp.back() < k) {
            dp.emplace_back(dp.back() + dp[dp.size()-2]);
        }
        int i = dp.size() - 1;
        int res = 0;
        while (k > 0) {
            if (k >= dp[i]) {
                res++;
                k-=dp[i];
            }
            else {
                i--;
            }
        }
        return res;
    }
};