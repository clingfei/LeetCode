/*
 * @lc app=leetcode.cn id=558 lang=golang
 *
 * [558] 四叉树交集
 */
package leetcode
// @lc code=start
/**
 * Definition for a QuadTree node.
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

// type Node struct {
//     Val bool
//     IsLeaf bool
//     TopLeft *Node
//     TopRight *Node
//     BottomLeft *Node
//     BottomRight *Node
// }

func or(t1, t2 bool) bool {
	return t1 || t2
}

func intersect(quadTree1 *Node, quadTree2 *Node) *Node {
    if quadTree1.IsLeaf && quadTree2.IsLeaf {
		return &Node{or(quadTree1.Val, quadTree2.Val), true, nil, nil, nil, nil}
	} else if !quadTree1.IsLeaf && quadTree2.IsLeaf {
		node := new(Node)
		node.TopLeft = intersect(quadTree1.TopLeft, quadTree2)
		node.TopRight = intersect(quadTree1.TopRight, quadTree2)
		node.BottomLeft = intersect(quadTree1.BottomLeft, quadTree2)
		node.BottomRight = intersect(quadTree1.BottomRight, quadTree2)
		if node.BottomLeft.IsLeaf && node.BottomRight.IsLeaf && node.TopLeft.IsLeaf && node.TopRight.IsLeaf {
			if node.BottomLeft.Val == node.BottomRight.Val && node.BottomLeft.Val == node.TopLeft.Val && node.BottomLeft.Val == node.TopRight.Val {
				node.IsLeaf = true
				node.Val = node.BottomLeft.Val
				node.BottomLeft, node.BottomRight, node.TopLeft, node.TopRight = nil, nil, nil, nil
			} else {
				node.IsLeaf = false
				node.Val = true
			}
		} else {
			node.IsLeaf = false
			node.Val = true
		}
		return node
	} else if quadTree1.IsLeaf && !quadTree2.IsLeaf {
		node := new(Node)
		node.TopLeft = intersect(quadTree1, quadTree2.TopLeft)
		node.TopRight = intersect(quadTree1, quadTree2.TopRight)
		node.BottomLeft = intersect(quadTree1, quadTree2.BottomLeft)
		node.BottomRight = intersect(quadTree1, quadTree2.BottomRight)
		if node.BottomLeft.IsLeaf && node.BottomRight.IsLeaf && node.TopLeft.IsLeaf && node.TopRight.IsLeaf {
			if node.BottomLeft.Val == node.BottomRight.Val && node.BottomLeft.Val == node.TopLeft.Val && node.BottomLeft.Val == node.TopRight.Val {
				node.IsLeaf = true
				node.Val = node.BottomLeft.Val
				node.BottomLeft, node.BottomRight, node.TopLeft, node.TopRight = nil, nil, nil, nil
			} else {
				node.IsLeaf = false
				node.Val = true
			}
		} else {
			node.IsLeaf = false
			node.Val = true
		}
		return node
	} else {
		node := new(Node)
		node.TopLeft = intersect(quadTree1.TopLeft, quadTree2.TopLeft)
		node.TopRight = intersect(quadTree1.TopRight, quadTree2.TopRight)
		node.BottomLeft = intersect(quadTree1.BottomLeft, quadTree2.BottomLeft)
		node.BottomRight = intersect(quadTree1.BottomRight, quadTree2.BottomRight)
		if node.BottomLeft.IsLeaf && node.BottomRight.IsLeaf && node.TopLeft.IsLeaf && node.TopRight.IsLeaf {
			if node.BottomLeft.Val == node.BottomRight.Val && node.BottomLeft.Val == node.TopLeft.Val && node.BottomLeft.Val == node.TopRight.Val {
				node.IsLeaf = true
				node.Val = node.BottomLeft.Val
				node.BottomLeft, node.BottomRight, node.TopLeft, node.TopRight = nil, nil, nil, nil
			} else {
				node.IsLeaf = false
				node.Val = true
			}
		} else {
			node.IsLeaf = false
			node.Val = true
		}
		return node
	}
}
// @lc code=end

