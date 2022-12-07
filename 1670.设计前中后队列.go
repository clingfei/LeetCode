/*
 * @lc app=leetcode.cn id=1670 lang=golang
 *
 * [1670] 设计前中后队列
 *
 * https://leetcode.cn/problems/design-front-middle-back-queue/description/
 *
 * algorithms
 * Medium (52.24%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 13.3K
 * Testcase Example:  '["FrontMiddleBackQueue","pushFront","pushBack","pushMiddle","pushMiddle","popFront","popMiddle","popMiddle","popBack","popFront"]\n' +
  '[[],[1],[2],[3],[4],[],[],[],[],[]]'
 *
 * 请你设计一个队列，支持在前，中，后三个位置的 push 和 pop 操作。
 *
 * 请你完成 FrontMiddleBack 类：
 *
 *
 * FrontMiddleBack() 初始化队列。
 * void pushFront(int val) 将 val 添加到队列的 最前面 。
 * void pushMiddle(int val) 将 val 添加到队列的 正中间 。
 * void pushBack(int val) 将 val 添加到队里的 最后面 。
 * int popFront() 将 最前面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
 * int popMiddle() 将 正中间 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
 * int popBack() 将 最后面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
 *
 *
 * 请注意当有 两个 中间位置的时候，选择靠前面的位置进行操作。比方说：
 *
 *
 * 将 6 添加到 [1, 2, 3, 4, 5] 的中间位置，结果数组为 [1, 2, 6, 3, 4, 5] 。
 * 从 [1, 2, 3, 4, 5, 6] 的中间位置弹出元素，返回 3 ，数组变为 [1, 2, 4, 5, 6] 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle",
 * "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
 * [[], [1], [2], [3], [4], [], [], [], [], []]
 * 输出：
 * [null, null, null, null, null, 1, 3, 4, 2, -1]
 *
 * 解释：
 * FrontMiddleBackQueue q = new FrontMiddleBackQueue();
 * q.pushFront(1);   // [1]
 * q.pushBack(2);    // [1, 2]
 * q.pushMiddle(3);  // [1, 3, 2]
 * q.pushMiddle(4);  // [1, 4, 3, 2]
 * q.popFront();     // 返回 1 -> [4, 3, 2]
 * q.popMiddle();    // 返回 3 -> [4, 2]
 * q.popMiddle();    // 返回 4 -> [2]
 * q.popBack();      // 返回 2 -> []
 * q.popFront();     // 返回 -1 -> [] （队列为空）
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 最多调用 1000 次 pushFront， pushMiddle， pushBack， popFront， popMiddle 和 popBack
 * 。
 *
 *
*/
package leetcode

// @lc code=start
type FrontMiddleBackQueue struct{}

var a []int

func Constructor() (_ FrontMiddleBackQueue) {
	a = nil
	return
}

func (FrontMiddleBackQueue) PushFront(v int) {
	a = append([]int{v}, a...)
}

func (FrontMiddleBackQueue) PushMiddle(v int) {
	p := len(a) / 2
	a = append(a[:p], append([]int{v}, a[p:]...)...)
}

func (FrontMiddleBackQueue) PushBack(v int) {
	a = append(a, v)
}

func (FrontMiddleBackQueue) PopFront() (ans int) {
	if len(a) == 0 {
		return -1
	}
	ans = a[0]
	a = a[1:]
	return
}

func (FrontMiddleBackQueue) PopMiddle() (ans int) {
	if len(a) == 0 {
		return -1
	}
	p := (len(a) - 1) / 2
	ans = a[p]
	a = append(a[:p], a[p+1:]...)
	return
}

func (FrontMiddleBackQueue) PopBack() (ans int) {
	if len(a) == 0 {
		return -1
	}
	ans = a[len(a)-1]
	a = a[:len(a)-1]
	return
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PushFront(val);
 * obj.PushMiddle(val);
 * obj.PushBack(val);
 * param_4 := obj.PopFront();
 * param_5 := obj.PopMiddle();
 * param_6 := obj.PopBack();
 */
// @lc code=end
