#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = nums.size() + 1;
        int i = 0, j = -1;
        int prefix = 0;
        while ( i < nums.size()) {
            if (prefix + nums[i] >= target) {
                if (j == -1 && i - j < min)
                    min = i - j;
                else if(i - j + 1 < min) min = i - j + 1;
                if (prefix > 0) {
                    prefix -= nums[j];
                    j++;
                }
                else if (prefix == 0) return 1;
            }
            else {
                if (prefix == 0) {
                    if (j >= 0) prefix += nums[i++];
                    else {j = i; prefix += nums[i]; i++;}
                }
                else prefix += nums[i++];
            }
        }
        return min == nums.size() + 1 ? 0 : min;
    }
};