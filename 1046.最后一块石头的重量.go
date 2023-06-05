/*
 * @lc app=leetcode.cn id=1046 lang=golang
 *
 * [1046] 最后一块石头的重量
 *
 * https://leetcode.cn/problems/last-stone-weight/description/
 *
 * algorithms
 * Easy (65.78%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    87.3K
 * Total Submissions: 132.7K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * 有一堆石头，每块石头的重量都是正整数。
 *
 * 每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x 。那么粉碎的可能结果如下：
 *
 *
 * 如果 x == y，那么两块石头都会被完全粉碎；
 * 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 *
 *
 * 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：[2,7,4,1,8,1]
 * 输出：1
 * 解释：
 * 先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
 * 再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
 * 接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
 * 最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */
package leetcode

import (
	"container/heap"
	"fmt"
)

// @lc code=start
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func lastStoneWeight(stones []int) int {
	h := IntHeap(stones)
	heap.Init(&h)
	for h.Len() >= 2 {
		x1 := heap.Pop(&h).(int)
		x2 := heap.Pop(&h).(int)
		if x1 == x2 {
			continue
		} else {
			heap.Push(&h, x1 - x2)
		}
	}
	if h.Len() == 0 {
		return 0
	} else {
		return heap.Pop(&h).(int)
	}
}
// @lc code=end

