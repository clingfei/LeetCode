/*
 * @lc app=leetcode.cn id=429 lang=golang
 *
 * [429] N 叉树的层序遍历
 *
 * https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (72.59%)
 * Likes:    335
 * Dislikes: 0
 * Total Accepted:    140K
 * Total Submissions: 192.9K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
 * 
 * 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：[[1],[3,2,4],[5,6]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树的高度不会超过 1000
 * 树的节点总数在 [0, 10^4] 之间
 * 
 * 
 */
package leetcode
type Node struct {
    Val int
    Children []*Node
}
// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
    var res [][]int
	var que []*Node
	if root != nil {
		que = append(que, root)
	}
	for len(que) > 0 {
		var tmp []int
		size := len(que)
		for  i := 0; i < size; i++ {
			p := que[0]
			que = que[1:]
			tmp = append(tmp, p.Val)
			for _, node := range p.Children {
				que = append(que, node)
			}
		}
		res = append(res, tmp)
	}
	return res
}
// @lc code=end

