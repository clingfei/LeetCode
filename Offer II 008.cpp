#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, cur = 0;
        int min = nums.size() + 1;
        for (int j = 0; j < nums.size(); ++j) {
            cur += nums[j];
            while (cur >= target) {
                cur -= nums[i];
                if (j - i + 1 < min) {
                    min = j - i + 1;
                    if (min == 1)
                        return 1;
                }
                ++i;
            }
        }
        return min == nums.size() + 1 ? 0 : min;
    }
};