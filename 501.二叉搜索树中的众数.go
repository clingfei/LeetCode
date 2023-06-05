/*
 * @lc app=leetcode.cn id=501 lang=golang
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (54.29%)
 * Likes:    568
 * Dislikes: 0
 * Total Accepted:    135.2K
 * Total Submissions: 248.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
 *
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 *
 * 假定 BST 满足如下定义：
 *
 *
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
func findMode(root *TreeNode) []int {
	var pre *TreeNode
	var res []int
	freq, curfreq := 0, 0
	var dfs func (*TreeNode)
	dfs = func(tn *TreeNode) {
		if tn == nil {
			return
		}
		dfs(tn.Left)
		if pre != nil {
			if tn.Val == pre.Val {
				curfreq++
			} else {
				if curfreq > freq {
					res = make([]int, 1)
					res[0] = pre.Val
					freq = curfreq
				} else if curfreq == freq {
					res = append(res, pre.Val)
				}
				curfreq = 1
			}
		} else {
			curfreq = 1
		}
		pre = tn
		dfs(tn.Right)
	}
	dfs(root)
	if curfreq > freq {
		res = make([]int, 1)
		res[0] = pre.Val
	} else if curfreq == freq {
		res = append(res, pre.Val)
	}
	return res
}
// @lc code=end

