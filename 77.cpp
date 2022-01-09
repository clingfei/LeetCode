#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        backtracing(temp, res, n, k);
        return res;
    }
    void backtracing(vector<int> &temp, vector<vector<int>> &res, int n, int k) {
        int i;
        if(temp.size() == 0) 
            i = 1;
        else 
            i = temp.back() + 1;
        while (i <= n - (k - temp.size()) + 1) {
            temp.push_back(i);
            if (temp.size() == k) 
                res.push_back(temp);
            else     
                backtracing(temp, res, n, k);
            temp.pop_back();
            ++i;   
        }
    }
};