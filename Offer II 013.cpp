#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (i > 0)
                    prefix[i][j] += prefix[i-1][j]; 
                if (j > 0)
                    prefix[j][j] += prefix[i][j-1];
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1]; 
                }
            }
        } 
    }   
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = 0;
        answer += prefix[row2][col2];
        if (col1 > 0)
            answer -= prefix[row2][col1 - 1];
        if (row1 > 0)
            answer -= prefix[row1 - 1][col2];
        if (col1 > 0 && row1 > 0)
            answer += prefix[row1 - 1][col1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */