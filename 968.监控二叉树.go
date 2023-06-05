/*
 * @lc app=leetcode.cn id=968 lang=golang
 *
 * [968] 监控二叉树
 *
 * https://leetcode.cn/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (52.19%)
 * Likes:    530
 * Dislikes: 0
 * Total Accepted:    51K
 * Total Submissions: 97.7K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * 给定一个二叉树，我们在树的节点上安装摄像头。
 * 
 * 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
 * 
 * 计算监控树的所有节点所需的最小摄像头数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[0,0,null,0,0]
 * 输出：1
 * 解释：如图所示，一台摄像头足以监控所有节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[0,0,null,0,null,0,null,null,0]
 * 输出：2
 * 解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数的范围是 [1, 1000]。
 * 每个节点的值都是 0。
 * 
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
func minCameraCover(root *TreeNode) int {
	cnt := 0
	// 返回值：
	// 0， 1， 2
	// 0表示无覆盖，无摄像头
	// 1表示有摄像头
	// 2表示有覆盖，无摄像头
	var traversal func (*TreeNode) int
	traversal = func (root *TreeNode) int {
		if root == nil {
			return 2
		}
		left := traversal(root.Left)
		right := traversal(root.Right)
		if left == 0 || right == 0 {
			cnt++
			return 1
		} else if left == 1 || right == 1{
			return 2
		} else {
			return 0
		}
	}
	res := traversal(root)
	if res == 0 {
		cnt++
	}
	return cnt
}
// @lc code=end

