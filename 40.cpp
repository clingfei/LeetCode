#include <vector>
#include <algorithm>
#include <map>

using namespace std;
//如何去重
class Solution {
private:
    void backtracing(vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp, int target, int cur, int last) {
        for (int i = last; i < candidates.size() && cur <= target; ++i) {
            if (i > last && candidates[i] == candidates[i-1]) continue;
            cur += candidates[i];
            temp.emplace_back(candidates[i]);
            if (cur == target) res.emplace_back(temp);
            else 
                backtracing(candidates, res, temp, target, cur, i + 1);
            cur -= candidates[i];
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtracing(candidates, res, temp, target, 0, 0);
        return res;
    }
};