#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = nums[0];
        for (int i = 0; i <= cover; ++i) {
            if (i + nums[i] > cover)
                cover = i + nums[i];
            if (cover >= nums.size()-1)
                return true;
        }
        return false;
    }   
};