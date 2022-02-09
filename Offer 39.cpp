#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                res = nums[i];
                cnt = 1;
            } else if(nums[i] != res) {
                cnt--;
            } else {
                cnt++;
            }
        }
        return res;
    }
};