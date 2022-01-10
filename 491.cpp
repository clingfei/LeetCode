#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        backtracing(res, nums, temp, 0);
        return res;
    }
    void backtracing(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp, int last) {
        unordered_set<int> uset;
        for (int i = last; i < nums.size(); ++i) {
            if (i > last && nums[i] == nums[i-1]) continue;
            if (uset.find(nums[i]) != uset.end()) continue;
            if (temp.size() == 0 || nums[i] >= temp.back())  {
                temp.emplace_back(nums[i]);
                uset.insert(nums[i]);
            }
            else continue;
            if (temp.size() > 1) {    
                res.emplace_back(temp);
            }
            backtracing(res, nums, temp, i+1);
            temp.pop_back();
        }
    }
};