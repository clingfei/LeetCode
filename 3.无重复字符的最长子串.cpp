/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    9209
 * Dislikes: 0
 * Total Accepted:    2.3M
 * Total Submissions: 6M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> hashmap;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (hashmap.find(s[j]) == hashmap.end()) {
                hashmap.insert(s[j]);
            } else {
                if (hashmap.size() > res) 
                    res = hashmap.size();
                while (i < j && s[i] != s[j]) {
                    hashmap.erase(s[i]);
                    i++;
                }
                if (i == j) {
                    hashmap.insert(s[i]);
                } else {
                    i++;
                }
            }
        }
        if (hashmap.size() > res) 
            return hashmap.size();
        else 
            return res;
    }
};
// @lc code=end

