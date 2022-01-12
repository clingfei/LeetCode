#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = 0;
        for (int j = 1; j < prices.size(); ++j) {
            if (prices[j] > min) { 
                if (prices[j] - min > max)
                    max = prices[j] - min;
            }
            else min = prices[j];
        }
        return max;
    }
};