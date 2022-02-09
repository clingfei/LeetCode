#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = 0;
        int i = 0;
        while (nums[i++] == 0) {
            zero++;
        }
        while (i < nums.size()) {
            if (nums[i] == nums[i-1]) return false;
            else if (nums[i] != nums[i-1] + 1) {
                if (zero >= nums[i] - nums[i-1] - 1) 
                    zero -= (nums[i] - nums[i-1] - 1);
                else return false;
            }
            ++i;
        }
        return true;
    }
};