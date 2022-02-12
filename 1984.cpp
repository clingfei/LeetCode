#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        sort(nums.begin(), nums.end());
        int min = nums[k - 1] - nums[0];
        for (int i = 1; i + k - 1 < nums.size(); ++i) {
            if (nums[i + k - 1] - nums[i] < min) 
                min = nums[i + k - 1] - nums[i];
        } 
        return min;
    }
};