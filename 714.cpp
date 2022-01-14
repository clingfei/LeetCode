#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int last = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - last > fee) {
                res += prices[i] - last - fee;
                last = prices[i] - fee;
            }
            else if (prices[i] < last) {
                last = prices[i];
            }
        }
        return res;
    }
};