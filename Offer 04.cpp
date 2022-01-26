#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int row = 0, col = matrix[0].size()-1;
        while (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()) {
            if (target < matrix[row][col]) {
                col--;
            }
            else if (target == matrix[row][col])
                return true;
            else row++;
        }
        return false;
    }
};