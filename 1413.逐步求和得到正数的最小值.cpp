/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix = 0;
        int min = 0;
        for (auto v : nums) {
            prefix += v;
            if (prefix < min) {
                min = prefix;
            }
        }
        return 1 - min;
    }
};
// @lc code=end

