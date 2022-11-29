/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    string reformat(string s) {
        string a, b, res;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                a.push_back(s[i]);
            } else {
                b.push_back(s[i]);
            }
        }
        if (a.size() == b.size() || a.size() == b.size() + 1) {
            for (int i = 0; i < b.size(); i++) {
                res.push_back(a[i]);
                res.push_back(b[i]);
            }
            if (a.size() == b.size() + 1)
                res.push_back(a[a.size() - 1]);
        } else if (a.size() + 1 == b.size()) {
            for (int i = 0; i < a.size(); i++) {
                res.push_back(b[i]);
                res.push_back(a[i]);
            }
            res.push_back(b[b.size() - 1]);
        } 
        return res;

    }
};
// @lc code=end

