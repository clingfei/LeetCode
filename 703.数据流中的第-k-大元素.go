/*
 * @lc app=leetcode.cn id=703 lang=golang
 *
 * [703] 数据流中的第 K 大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (52.36%)
 * Likes:    397
 * Dislikes: 0
 * Total Accepted:    81.3K
 * Total Submissions: 155.4K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n' +
  '[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
 *
 * 请实现 KthLargest 类：
 *
 *
 * KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
 * int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入：
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * 输出：
 * [null, 4, 5, 5, 8, 8]
 *
 * 解释：
 * KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
 * kthLargest.add(3);   // return 4
 * kthLargest.add(5);   // return 5
 * kthLargest.add(10);  // return 5
 * kthLargest.add(9);   // return 8
 * kthLargest.add(4);   // return 8
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0
 * -10^4
 * -10^4
 * 最多调用 add 方法 10^4 次
 * 题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
 *
 *
*/
package leetcode

import (
	"container/heap"
	"sort"
)

// @lc code=start
type KthLargest struct {
	k    int
	sort.IntSlice
}

func (kl *KthLargest) Push(v interface{}) {
    kl.IntSlice = append(kl.IntSlice, v.(int))
}

func (kl *KthLargest) Pop() interface{} {
    a := kl.IntSlice
    v := a[len(a) - 1]
    kl.IntSlice = a[:len(a) - 1]
    return v
}

func Constructor(k int, nums []int) KthLargest {
	kl := KthLargest{k: k}
    for _, val := range nums {
        kl.Add(val)
    }
    return kl
}

// 其实只要维护前k大的元素就够了
func (this *KthLargest) Add(val int) int {
	heap.Push(this, val)
    if this.Len() > this.k {
        heap.Pop(this)
    }
    return this.IntSlice[0]
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */
// @lc code=end
