#include <vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            int min = matrix[i][0];
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            row[i] = min;
        }
        vector<int> col(matrix[0].size(), 0);
        for (int i = 0; i < matrix[0].size(); ++i) {
            int max = 0;
            for (int j = 1; j < matrix.size(); ++j) {
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
            col[i] = max;
        }
        vector<int> res;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == row[i] && matrix[i][j] == col[j])
                    res.emplace_back(matrix[i][j]);
            }
        }
        return res;
    }
};