#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracing(board, 0, 0);
    }
    bool backtracing(vector<vector<char>>& board, int row, int i) {
        if (board[row][i] != '.') {
            if (i == 8 && row == 8)
                return true;
            if (i == 8)
                return backtracing(board, row + 1, 0);
            else 
                return backtracing(board, row, i + 1);
        }
        for (int j = '1'; j <= '9'; ++j) {
            if (check(board, row, i, j)) {
                board[row][i] =  j;
                if (i == 8 && row == 8)
                    return true;
                bool flag;
                if (i == 8)
                    flag = backtracing(board, row + 1, 0);
                else flag = backtracing(board, row, i + 1);
                if (flag) return true;

                board[row][i] = '.';
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, int row, int i, char j) {            //row是行，i是列，j是对应的目标
        for (int k = 0; k < 9; ++k) {
            if (board[row][k] == j)                  //检测行
                return false;
        }
        for (int k = 0; k < 9; ++k) {
            if (board[k][i] == j)
                return false;
        }
        int k, m;
        if (row >= 0 && row < 3)
            row = 0;
        else if (row >=3 && row < 6)
            row = 3;
        else row =6;
        if (i >= 0 && i < 3)
            i = 0;
        else if (i >=3 && i < 6)
            i= 3;
        else i =6;
        for (int k = row; k < row + 3; ++k) {
            for (int m = i; m < i + 3; ++m) {
                if (board[k][m] == j)
                    return false;
            }
        }
        return true;
    }
};