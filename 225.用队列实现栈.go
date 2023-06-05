/*
 * @lc app=leetcode.cn id=225 lang=golang
 *
 * [225] 用队列实现栈
 *
 * https://leetcode.cn/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (66.99%)
 * Likes:    635
 * Dislikes: 0
 * Total Accepted:    246.5K
 * Total Submissions: 368.3K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 
 * 实现 MyStack 类：
 * 
 * 
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty
 * 这些操作。
 * 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 2, 2, false]
 * 
 * 解释：
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // 返回 2
 * myStack.pop(); // 返回 2
 * myStack.empty(); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= x <= 9
 * 最多调用100 次 push、pop、top 和 empty
 * 每次调用 pop 和 top 都保证栈不为空
 * 
 * 
 * 
 * 
 * 进阶：你能否仅用一个队列来实现栈。
 * 
 */
package leetcode
// @lc code=start
type MyStack struct {
	queue1 Queue
	queue2 Queue
}

type Queue []int

func (q *Queue) Push(x int) {
	*q = append(*q, x)
}

func (q *Queue) Pop() int {
	res := (*q)[0]
	*q = (*q)[1:]
	return res
}

func (q *Queue) isEmpty() bool {
	return len(*q) == 0
}

func (q *Queue) front() int {
	return (*q)[0]
}


func Constructor() MyStack {
	var stack MyStack
	stack.queue1 = make([]int, 0)
	stack.queue2 = make([]int, 0)
	return stack
}


func (this *MyStack) Push(x int)  {
	this.queue2.Push(x)
	for !this.queue1.isEmpty() {
		t := this.queue1.Pop()
		this.queue2.Push(t)
	}
	for !this.queue2.isEmpty() {
		t := this.queue2.Pop()
		this.queue1.Push(t)
	}
}


func (this *MyStack) Pop() int {
	res := this.queue1.Pop()
	return res
}


func (this *MyStack) Top() int {
	res := this.queue1.front()
	return res
}


func (this *MyStack) Empty() bool {
	return this.queue1.isEmpty()
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
// @lc code=end

