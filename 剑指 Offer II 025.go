package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type ListNode struct {
    Val int
    Next *ListNode
}
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	st1, st2 := make([]*ListNode, 0), make([]*ListNode, 0)
	p := l1
	for p != nil {
		st1 = append(st1, p)
		p = p.Next
	}
	p = l2
	for p != nil {
		st2 = append(st2, p)
		p = p.Next
	}
	if len(st1) < len(st2) {
		st1, st2 = st2, st1
	}
	len1, len2 := len(st1) - 1, len(st2) - 1
	carry := 0
	for len1 >= 0 && len2 >= 0 {
		num := st1[len1].Val + st2[len2].Val + carry
		carry = num / 10
		node := ListNode{num % 10, p}
		p = &node
		len1--
		len2--
	}
	for len1 >= 0 {
		num := st1[len1].Val + carry
		carry = num / 10
		node := ListNode{num % 10, p}
		p = &node
		len1--
	}
	if carry > 0 {
		node := ListNode{carry, p}
		p = &node
	}
	return p
}