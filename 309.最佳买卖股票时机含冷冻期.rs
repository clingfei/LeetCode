/*
 * @lc app=leetcode.cn id=309 lang=rust
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (63.88%)
 * Likes:    1361
 * Dislikes: 0
 * Total Accepted:    222.6K
 * Total Submissions: 348.4K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 * 示例 2:
 * 
 * 
 * 输入: prices = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// @lc code=start
use std::cmp::max;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut dp = vec![vec![0; 3]; prices.len()];
        dp[0][0] = -prices[0];
        let mut i: usize = 1;
        while i < prices.len() {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][2], dp[i - 1][1]);
            // dp[i - 1][0]有两种可能：i-1天刚买，i-2天买了，但是如何规避i-1天刚买的情况？
            dp[i][2] = dp[i - 1][0] + prices[i];
            i+=1;
        }
        return max(dp[prices.len() - 1][1], dp[prices.len() - 1][2]);
    }
}
// @lc code=end

