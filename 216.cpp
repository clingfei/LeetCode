#include <vector>

using namespace std;

class Solution {
private:
    void backtracing(vector<int> &temp, vector<vector<int>> &res, int k, int n, int cur) {
        int start = 1;
        if (temp.size() == 0)
            start = 1;
        else 
            start = temp.back() + 1;
        for (int i = start; i <= 9 && i <= n - cur; ++i) {
            cur += i;
            temp.emplace_back(i);
            if (temp.size() == k && cur == n)
                res.emplace_back(temp);
            else backtracing(temp, res, k, n, cur);
            cur -= i;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracing(temp, res, k, n, 0);
        return res;
    }
};