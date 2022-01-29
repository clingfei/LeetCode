#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                return vector<int>{nums[i], nums[j]};
            }
            else if (nums[i] + nums[j] < target) {
                ++i;
            }
            else {
                --j;
            }
        }
        return vector<int>();
    }
};