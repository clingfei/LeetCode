#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.emplace_back(temp);
        sort(nums.begin(), nums.end());
        backtracing(res, nums, temp, 0);
        return res;
    }
    void backtracing(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, int last) {
        for (int i = last; i < nums.size(); ++i) {
            temp.emplace_back(nums[i]);
            res.emplace_back(temp);             
            backtracing(res, nums, temp, i + 1);
            temp.pop_back();
        }
    }
};