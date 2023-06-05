/*
 * @lc app=leetcode.cn id=647 lang=golang
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (66.90%)
 * Likes:    1058
 * Dislikes: 0
 * Total Accepted:    245.7K
 * Total Submissions: 367.2K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 */
package leetcode
// @lc code=start
func countSubstrings(s string) int {
    res:=0
    dp:=make([][]bool,len(s))
    for i:=0;i<len(s);i++{
        dp[i]=make([]bool,len(s))
    }

    for i:=len(s)-1;i>=0;i--{
        for j:=i;j<len(s);j++{
            if s[i]==s[j]{
                if j-i<=1{
                    res++
                    dp[i][j]=true
                }else if dp[i+1][j-1]{
                    res++
                    dp[i][j]=true
                }
            }
        }
    }
    return res
}
// @lc code=end

