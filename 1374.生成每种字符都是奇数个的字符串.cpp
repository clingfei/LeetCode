/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string generateTheString(int n) {
        string res;
        if (n & 1) { //odd
            res = string(n, 'a');
        } else {
            res = string(n-1, 'a');
            res.push_back('b');
        }
        return res;
    }
};
// @lc code=end

