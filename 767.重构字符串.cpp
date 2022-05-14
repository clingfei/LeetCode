/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> alpha(26, 0);
        int i = 0, m = 0;
        for (auto c : s) {
            if (++alpha[c - 'a'] >  alpha[m]) {
                m = c - 'a';
            }
        } 
        if (alpha[m] > (s.size() + 1) / 2) {
            return "";
        }
        while (--alpha[m] >= 0) {
            s[i] = 'a' + m;
            i += 2;
        }
        for (int j = 0; j < 26; ++j) {
            while (--alpha[j] >= 0) {
                if (i >= s.size()) 
                    i = 1;
                s[i] = j + 'a';
                i += 2;     
            }
        }
        return s;
    }
};
// @lc code=end

