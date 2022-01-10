#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        backtracing(res, temp, n);
        return res;
    }
    void backtracing(vector<vector<string>> &res, vector<string> &temp, int n) {
        for (int i = 0; i < n; ++i) {
            if (check(temp, i, n)) {
                string tmp;
                for (int j = 0; j < i; ++j)
                    tmp.push_back('.');
                tmp.push_back('Q');
                for (int j = i + 1; j < n; ++j)
                    tmp.push_back('.');
                temp.emplace_back(tmp);
                if (temp.size() == n)
                    res.emplace_back(temp);
                else 
                    backtracing(res, temp, n);
                temp.pop_back();
            }
        }
    }
    bool check(vector<string> temp, int index, int n) {
        if (temp.size() == 0)
            return true;
        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j][index] == 'Q')
                return false;
        }
        for (int i = 1; i <= index && i <= temp.size(); ++i) {
            if (temp[temp.size() - i][index-i] == 'Q')
                return false;
        }
        for (int i = 1; i +index < n && i <= temp.size(); ++i) {
            if (temp[temp.size()-i][index+i] == 'Q')
                return false;
        }
        return true;
    }
};