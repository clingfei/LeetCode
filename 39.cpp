#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
private:
    void backtracing(vector<vector<int>> &res, vector<int> temp, int target, int cur, vector<int>& candidates, int last) {
        for (int i = last; i < candidates.size() && cur + candidates[i] <= target; ++i) {
            temp.push_back(candidates[i]);
            cur += candidates[i];
            if (cur == target)
                res.emplace_back(temp);
            else 
                backtracing(res, temp, target, cur, candidates, i);
            cur -= candidates[i];
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtracing(res, temp, target, 0, candidates, 0);
        return res;
    }
};