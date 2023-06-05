/*
 * @lc app=leetcode.cn id=101 lang=golang
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.52%)
 * Likes:    2227
 * Dislikes: 0
 * Total Accepted:    747.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 * 
 */
package leetcode
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
func isSymmetric(root *TreeNode) bool {
	// 如何迭代？直接开始层次遍历
	var que []*TreeNode
	if root == nil {
		return true
	}
	que = append(que, root)
	for len(que) > 0 {
		size := len(que)
		for i := 0; i < size / 2; i++ {
			p, q := que[i], que[size - 1 - i]
			if p == nil && q == nil {
				continue
			} else if p == nil || q == nil {
				return false 
			} else if p.Val == q.Val {
				continue
			} else {
				return false 
			}
		}
		for i := 0; i < size; i++ {
			p := que[0]
			que = que[1:]
			if p != nil {
				que = append(que, p.Left)
				que = append(que, p.Right)
			}
		}	
	}
	return true
}
// @lc code=end

