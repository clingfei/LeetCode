#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res(matrix.size() * matrix[0].size(), 0);
        int i = 0, j = 0;
        int direction = 0;
        int cnt = 0;
        while (cnt < res.size()) {
            res[cnt++] = matrix[i][j];
            matrix[i][j] = -101;
            switch(direction) {
                case 0: if (j + 1 == matrix[0].size() || matrix[i][j + 1] == -101) direction = (direction + 1) % 4; break;
                case 1: if (i + 1 == matrix.size() || matrix[i + 1][j] == -101) direction = (direction + 1) % 4; break;
                case 2: if (j == 0 || matrix[i][j - 1] == -101) direction = (direction + 1) % 4; break;
                case 3: if (i == 0 || matrix[i - 1][j] == -101) direction = (direction + 1) % 4; 
            }
            switch(direction) {
                case 0: j++; break;
                case 1: i++; break;
                case 2: j--; break;
                case 3: i--;
            }
        }
        return res;
    }
};