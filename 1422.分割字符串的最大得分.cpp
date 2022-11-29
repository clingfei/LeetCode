/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int onen = 0, zeron = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                zeron++;
            } else {
                onen++;
            }
        }
        int maxscore = s[0] == '0'? 1 + onen : onen - 1;
        int cur = maxscore;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                cur++;
                if (cur > maxscore) {
                    maxscore = cur;
                }
            } else {
                cur--;
            }
        }
        return maxscore;
    }
};
// @lc code=end

