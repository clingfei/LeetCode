/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        for (auto &word : words) {
            if (isSub(word, s)) {
                res++;
            }
        }
        return res;
    }
    bool isSub(string& word, string& s) {
        size_t p = 0;
        for (auto ch : word) {
            p = s.find(ch, p);
            if (p == string::npos) 
                return false;
            else 
                p++;
        }
        return true;
    }
};
// @lc code=end

