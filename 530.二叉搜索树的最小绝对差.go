/*
 * @lc app=leetcode.cn id=530 lang=golang
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (63.46%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    152K
 * Total Submissions: 239.5K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是 [2, 10^4]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
 *
 */
package leetcode

import "fmt"
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getMinimumDifference(root *TreeNode) int {
	if root == nil {
		return 0
	}
	_, _, res := dfs(root)
	return res
}
// 返回以root为根的二叉搜索树的最大值
func dfs(root *TreeNode) (max, min, diff int) {
	// 保证root不是nil
	max, min, diff = root.Val, root.Val, 1<<31-1
	if root.Left != nil {
		lmax, lmin, ldiff := dfs(root.Left)
		// fmt.Println(root.Val, lmax, lmin, ldiff)
		if root.Val - lmax < ldiff {
			diff = root.Val - lmax
		} else {
			diff = ldiff
		}
		min = lmin
	}
	if root.Right != nil {
		rmax, rmin, rdiff := dfs(root.Right)
		// fmt.Println(root.Val, rmax, rmin, rdiff)
		max = rmax
		if rmin - root.Val < diff {
			diff = rmin - root.Val
		}
		if rdiff < diff {
			diff = rdiff
		}
	}
	return
}
// @lc code=end

