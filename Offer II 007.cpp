#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) 
            return res;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, k = nums.size() - 1;        
        while (i < k) {
            j = i + 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    while (j + 1 < nums.size() && nums[j] == nums[j+1])
                        ++j;
                    ++j;
                } else {
                    while (k - 1 >= 0 && nums[k] == nums[k-1])
                        --k;
                    --k;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
            ++i;
            if (i + 2 >= nums.size() || nums[i] + nums[i + 1] + nums[i + 2] > 0) 
                return res;
        }
        return res;
    }
};