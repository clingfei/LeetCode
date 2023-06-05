/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.30%)
 * Likes:    1324
 * Dislikes: 0
 * Total Accepted:    250.7K
 * Total Submissions: 342K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
private:
    bool check(string s, int left, int right) {
        int l = left, r = right;
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    // idx表示idx之前的字符串已经划分成了path
    void dfs(vector<vector<string>>& res, vector<string>&path , string s, int idx) {
        if (idx >= s.size()) {
            res.push_back(path);
        }
        for (int i = idx; i < s.size(); i++) {
            if (check(s, idx, i)) { // 如果从idx到i是回文串
                path.push_back(s.substr(idx, i - idx + 1));
                dfs(res, path, s, i + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(res, path, s, 0);
        return res;
    }
};
// @lc code=end

