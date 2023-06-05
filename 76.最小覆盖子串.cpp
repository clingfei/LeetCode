/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.18%)
 * Likes:    2524
 * Dislikes: 0
 * Total Accepted:    426.5K
 * Total Submissions: 944K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> target;
        unordered_map<char, int> cur;
        for (auto ch : t) 
            target[ch]++;
        int cnt = t.size();
        int j = 0, i = 0;
        int left = 0, right = s.size();
        for (i = 0; i < s.size(); i++) {
            cur[s[i]]++;
            if (target.find(s[i]) != target.end() && cur[s[i]] <= target[s[i]]) 
                cnt--;
            while (cnt == 0 && j <= i) {
                if (i - j <= right - left) {
                    left = j;
                    right = i;
                }
                cur[s[j]]--;
                if (target.find(s[j]) != target.end() && cur[s[j]] < target[s[j]])
                    cnt++;
                ++j;
            }   
        }
        if (right == s.size())
            return "";
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

