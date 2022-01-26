#include <vector>

using namespace std;

class Solution {
    int max = 0;
    int cur = 0;
public:
    int maximumGood(vector<vector<int>>& statements) {
        vector<int> temp(statements.size(), -1);
        backtracing(statements, 0, temp);
        return max;
    }
    void backtracing(vector<vector<int>> & statements, int row, vector<int> temp) {
            //第row个是坏人
            int i = 0;
            vector<int> temp1 = temp;
            if (temp[row] != 1) {
                temp[row] = 0;
                if (row == statements.size()-1) {
                    if (cur > max)
                        max = cur;
                } 
                else {
                    backtracing(statements, row+1, temp);
                }

            }
            if (temp1[row]!=0) {
                // row是好人
                i = 0;
                temp1[row] = 1;
                for (; i < statements.size(); ++i) {
                    if (statements[row][i] == 1) {
                        if (temp1[i] == 0)
                            break;
                        else if (temp1[i] == -1)
                            temp1[i] = 1;
                    }
                    else if (statements[row][i] == 0){
                        if (temp1[i] == 1) break;
                        else if (temp1[i] == -1)
                            temp1[i] = 0;
                    }
                }      
                if (i == statements.size()) {
                cur++;
                if (row == statements.size()-1) {
                    if (cur > max)
                        max = cur;
                }
                else 
                    backtracing(statements, row+1, temp1);
                cur--;
            }
            }
    }
};