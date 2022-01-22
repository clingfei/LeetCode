#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0;
        int i = cost.size()-1;
        sort(cost.begin(), cost.end());
        while (i >= 0) {
            res += cost[i--];
            if (i >= 0)
                res += cost[i--];
            --i;
        }
        return res;
    }
};