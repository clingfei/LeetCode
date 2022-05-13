/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        if (strs.size() == 0 || strs.size() == 1)
            return res;
        int n = strs[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] < strs[j - 1][i]) {
                    res++;
                    break;
                } 
            }
        }
        return res;
    }
};
// @lc code=end

