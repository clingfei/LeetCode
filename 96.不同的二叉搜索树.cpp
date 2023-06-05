/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (70.77%)
 * Likes:    2013
 * Dislikes: 0
 * Total Accepted:    315.9K
 * Total Submissions: 446.4K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
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
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // dp[i]表示从1 到i为根的二叉搜索树总和
        vector<int>dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // 以j为根节点的二叉搜索树的数量 = 左子树的数量 * 右子树的数量
                // 左子树的数量是从0到j - 1的二叉搜索树的数量
                // 右子树的数量是从j + 1到i的二叉搜索树的数量，也就是dp[i-j]， 因为只关注数量而不关注值
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

