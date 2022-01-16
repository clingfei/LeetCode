#include <vector>

class Solution {
public:
    int numTrees(int n) {
        double res = 1;
        for (int i = n+2; i <= 2*n; ++i) {
            res *=i;
        }
        for (int i=1; i <= n; ++i) {
            res /= i;
        }
        return res + 0.5;
    }
};