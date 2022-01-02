#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, m = nums.size() - 1; 
                while (k < m) {
                    if (nums[i] + nums[j] + nums[k] + nums[m] > target) m--;
                    else if (nums[i] + nums[j] + nums[k] + nums[m] < target) k++;
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[m]});
                        while (m > k && nums[m] == nums[m - 1]) m--;
                        while (k < m && nums[k] == nums[k + 1]) k++;
                        k++;
                        m--;
                    } 
                }
            }
        }
        return res;
    }
};