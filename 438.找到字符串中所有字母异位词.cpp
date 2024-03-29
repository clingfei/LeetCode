/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.70%)
 * Likes:    1182
 * Dislikes: 0
 * Total Accepted:    290.1K
 * Total Submissions: 530.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;
        vector<int> pFreq(26);
        for (int i = 0; i < p.size(); ++i) 
            pFreq[p[i] - 'a']++;
        vector<int> sFreq(26);
        int cnt = p.size();
        for (int i = 0; i < s.size(); ++i) {
            if (++sFreq[s[i] - 'a'] <= pFreq[s[i] - 'a']) 
                cnt--;
            if (i >= p.size()) {
                sFreq[s[i - p.size()] - 'a']--;
                if (sFreq[s[i - p.size()] - 'a'] < pFreq[s[i - p.size()] - 'a'])
                    cnt++;
            }
            if (cnt == 0)
                res.emplace_back(i - p.size() + 1);
        }
        return res;
    }
};
// @lc code=end

