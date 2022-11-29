/*
 * @lc app=leetcode.cn id=5 lang=rust
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.26%)
 * Likes:    5930
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.4M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let sv = s.chars().collect::<Vec<char>>();
        let mut left: usize= 0;
        let mut right: usize = 0;
        let mut maxlen: i32 = 1;
        let mut i: i32 = 0;
        while i < s.len() as i32 {
            let mut l = i - 1;
            let mut r = i + 1;
            let mut curlen = 1;
            while l >= 0 && r < s.len() as i32 {
                if sv[l as usize] == sv[r as usize] {
                    curlen = r - l + 1;
                    l -= 1;
                    r += 1;
                } else {
                    break;
                }
            }
            if curlen > maxlen {
                maxlen = curlen;
                left = l as usize + 1;
                right = r as usize - 1;
            }
            l = i;
            r = i + 1;
            curlen = 0;
            while l >= 0 && r < s.len() as i32 {
                if sv[l as usize] == sv[r as usize] {
                    curlen = r - l + 1;
                    l -= 1;
                    r += 1;
                } else {
                    break;
                }
            }
            if curlen > maxlen {
                maxlen = curlen;
                left = l as usize + 1;
                right = r as usize - 1;
            }
            i += 1;
        }
        return s[left..right + 1].to_string()
    }
}
// @lc code=end

