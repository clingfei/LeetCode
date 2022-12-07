/*
 * @lc app=leetcode.cn id=264 lang=rust
 *
 * [264] 丑数 II
 *
 * https://leetcode.cn/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (58.81%)
 * Likes:    1010
 * Dislikes: 0
 * Total Accepted:    146K
 * Total Submissions: 248.3K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 * 
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
use std::cmp::min;
impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let mut ugly = vec![1];
        let mut p1 = 0;
        let mut p2 = 0;
        let mut p3 = 0;
        let mut i: usize = 1;
        while i < n as usize {
            ugly.push(min(min(ugly[p1] * 2, ugly[p2] * 3), ugly[p3] * 5));
            if ugly[i] == ugly[p1] * 2 {
                p1+=1;
            } 
            if ugly[i] == ugly[p2] * 3 {
                p2+=1;
            }
            if ugly[i] == ugly[p3] * 5 {
                p3+=1;
            }
            i += 1;
        }
        return ugly[n as usize - 1];
    }
}
// @lc code=end

