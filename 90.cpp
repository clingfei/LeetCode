#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        res.emplace_back(temp);
        backtracing(res, nums, temp, 0);
        return res;
    }
    void backtracing(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, int last) {
        for (int i = last; i < nums.size(); ++i) {
            if (i > last && nums[i] == nums[i - 1])
                continue;
            temp.emplace_back(nums[i]);
            res.emplace_back(temp);
            backtracing(res, nums, temp, i+1);
            temp.pop_back();
        }
    }
};