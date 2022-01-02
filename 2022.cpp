#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            vector<vector<int>> res;
            return res;
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        int cnt = 0, i = 0, j = 0;
        while (cnt < original.size()) {
            if (j == res[0].size()) {
                j = 0;
                ++i;
            }
            res[i][j++] = original[cnt++];
        }
        return res;
    }
};