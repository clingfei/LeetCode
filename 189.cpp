#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
         * 1. 复制一遍
         * 2. 每一行复制一遍
         * 3. 一位一位的移动
         */
        vector<int> res(nums.size());
        for (int i = 0; i < res.size(); ++i) {
            res[(i + k) % nums.size()] = nums[i]; 
        }
        nums = std::move(res);
    }

    //左转时：先转前k个，再转后面的，最后全部逆转
    //右转时，先将整个数组逆置，再将两部分分别逆置
    void reverse(vector<int>& nums, int begin, int end) {
        while (begin < end) {
            int temp = nums[begin];
            nums[begin++] = nums[end];
            nums[end--] = temp;
        }
    }
};