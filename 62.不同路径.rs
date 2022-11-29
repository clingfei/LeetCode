/*
 * @lc app=leetcode.cn id=62 lang=rust
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (67.56%)
 * Likes:    1619
 * Dislikes: 0
 * Total Accepted:    542.6K
 * Total Submissions: 803.2K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：m = 3, n = 7
 * 输出：28
 * 
 * 示例 2：
 * 
 * 
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：m = 7, n = 3
 * 输出：28
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：m = 3, n = 3
 * 输出：6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 题目数据保证答案小于等于 2 * 10^9
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let mut dp = vec![vec![0; n as usize]; m as usize];
        for i in 0..n as usize {
            dp[0][i] = 1 as i32;
        }
        for i in 0..m as usize {
            dp[i][0] = 1 as i32;
        }
        for i in 1..m as usize {
            for j in 1..n as usize {
                dp[i][j] = dp[i-1][j] + dp[i][j - 1];
            }
        }
        dp[m as usize - 1][n as usize - 1]
    }
}
// @lc code=end

