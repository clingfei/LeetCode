#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.size() == 0) return vector<int>{};
        vector<int> dp(a.size(), 1);
        for (int i = 1; i < a.size(); ++i) {
            dp[i] = dp[i-1] * a[i - 1];
        }
        int tmp = 1;
        for (int i = a.size() - 2; i >= 0; --i) {
            tmp *= a[i + 1];
            dp[i] *= tmp;
        }
        return dp;
    }
};