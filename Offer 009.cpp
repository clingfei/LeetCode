#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long cur = 1;
        int i = 0, j = 0;
        int res = 0;
        for (int j = 0; j < nums.size(); ++j) {
            cur *= nums[j];
            while (cur >= k && i <= j ) {
                cur /= nums[i];
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};