/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 *
 * https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (58.23%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    24K
 * Total Submissions: 41.2K
 * Testcase Example:  '"bcabc"'
 *
 * 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
 * 
 * 注意：该题与 316 https://leetcode.com/problems/remove-duplicate-letters/ 相同
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母组成
 * 
 * 
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> map(26, 0);
        vector<int> hashmap(26, 0);
        for (int i = 0; i < s.size(); i++) {
            map[s[i] - 'a']++;
        }
        int i = 0;
        stack<char> sta;
        while (i < s.size()) {
            if (hashmap[s[i] - 'a'] > 0) {
                map[s[i] - 'a']--;
                i++;
            } else if (sta.empty() || s[i] > sta.top() || map[sta.top() - 'a'] <= 0) {
                sta.push(s[i]);
                map[s[i] - 'a']--;
                hashmap[s[i] - 'a']++;
                i++;
            } else {
                hashmap[sta.top() - 'a']--;
                sta.pop();
            }
        }
        int size = sta.size();
        string res(size, ' ');
        for (int i = size -1; i >= 0; i--) {
            res[i] = sta.top();
            sta.pop();
        }
        return "";
    }
};
// @lc code=end

