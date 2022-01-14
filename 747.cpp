#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() < 1) return -1;
        if (nums.size() == 1) return 0;
        int index;
        int max, lmax;
        if (nums[0] > nums[1]) {
            max = nums[0];
            lmax = nums[1];
            index = 0;
        }
        else {
            max = nums[1];
            lmax = nums[0];
            index = 1;
        }
        
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] > max) {
                lmax = max;
                max = nums[i];
                index = i;
            }
            else if (nums[i] > lmax)
                lmax = nums[i];
        }
        return max >= 2*lmax ? index : -1;
    }
};