#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> tmp (32, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < 32; ++j) {
                tmp[j] += nums[i] & 1;
                nums[i] >>= 1;
            }
        }
        int ans = 0;
        for (int i = 31; i >=0; --i) {
            ans = (ans << 1) + (tmp[i] % 3);
        }
        return ans;
    }
};