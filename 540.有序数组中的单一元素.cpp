/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (mid != 0 && nums[mid] == nums[mid - 1]) {
                if ((mid - low  + 1) % 2 == 0) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else if (mid + 1 != nums.size() && nums[mid] == nums[mid + 1]) {
                if ((mid - low + 1) % 2 == 1) {
                    low = mid;
                } else {
                    high = mid; 
                }
            } else {
                return nums[mid];
            }
        }
        return nums[low];
    }
};
// @lc code=end

