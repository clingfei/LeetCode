#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n ,vector<int>(n, 0));
        int direction = 0;
        int i = 0, j = 0;
        int cur = 1;
        while (cur <= n * n) {
            res[i][j] = cur++;
            switch(direction % 4) {
                case 0: if (j + 1 >= n || res[i][j + 1] != 0) direction++; break;
                case 1: if (i + 1 >= n || res[i + 1][j] != 0) direction++; break;
                case 2: if (j == 0 || res[i][j - 1] != 0) direction++; break;
                case 3: if (i == 0 || res[i - 1][j] != 0) direction++; break;
            }
            switch(direction % 4) {
                case 0: j++; break;
                case 1: i++; break;
                case 2: j--; break;
                case 3: i--; break;
            }
        }
        return res;
    }
};