package leetcode

type ListNode struct {
    Val int
    Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
    p1, p2 := headA, headB
	flag1, flag2 := false, false 
	for p1 != nil && p2 != nil {
		if p1 == p2 {
			break
		}
		p1, p2 = p1.Next, p2.Next
		if p1 == nil {
			if flag1 {
				break
			}
			flag1 = true
			p1 = headB
		}
		if p2 == nil {
			if flag2 {
				break
			}
			flag2 = true
			p2 = headA
		}
	}
	if p1 == p2 {
		return p1
	} else {
		return nil
	}	
}