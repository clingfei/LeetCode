#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i-1])
            ++i;
        int j = nums.size() - 2;
        while (j >= i && nums[j] == nums[j+1])
            --j;
        int res = 0;
        res = j - i+1;
        return res;
    }
};