#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtracing(res, nums, temp, used);
        return res;
    }
    void backtracing(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, vector<bool> &used) {
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); ++i) {
            if (uset.find(nums[i]) != uset.end() || used[i] == true)    continue;
            temp.emplace_back(nums[i]);
            used[i] = true;
            uset.insert(nums[i]);
            if (temp.size() == nums.size())
                res.emplace_back(temp);
            else 
                backtracing(res, nums, temp, used);
            temp.pop_back();
            used[i] = false;     
        }
    }
};