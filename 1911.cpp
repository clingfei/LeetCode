#include <vector>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])
                res += nums[i] - nums[i-1];
        }
        return res;
    }
};