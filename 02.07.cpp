struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        bool flag1 = false, flag2 = false;
        while (p1 != nullptr && p2 !=nullptr) {
            p1 = p1->next;    
            p2 = p2->next;
            if (p1 == nullptr && !flag1) {
                p1 = headB;
                flag1 = !flag1;
            }
            if (p2 == nullptr && !flag2) {
                p2 = headA;
                flag2 = !flag2;
            }
            if (p1 == p2)
                return p1;
        }
        return nullptr;
    }
};