#include <vector>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) {
                if (i > 1 && nums[i] <= nums[i - 2]) 
                    nums[i] = nums[i-1];
                cnt++;
                if (cnt > 1) return false;
            }
        }
        return true;
    }
};