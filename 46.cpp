#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        backtracing(res, nums, used, temp);
        return res;
    }
    void backtracing(vector<vector<int>> &res, vector<int> &nums, vector<bool> &used, vector<int> &temp) {
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == true) continue;
            temp.emplace_back(nums[i]);
            used[i] = true;
            if (temp.size() == nums.size())
                res.emplace_back(temp);
            else 
                backtracing(res, nums, used, temp);
            temp.pop_back();
            used[i] = false;
        }
    }
};