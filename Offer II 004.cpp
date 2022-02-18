#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int temp = 0;
            for (int num : nums) {
                temp += (num >> i) & 1;
            }
            res |= (temp % 3) << i;
        }
        return res;
    }
};