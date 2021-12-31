struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *q = head, *p = head;
        while (cnt++ < n) {
            q = q->next;
        }

        while (q != nullptr) {
            p = p->next;
            q = q->next;
        }
        if (p == head) {
            head = p->next;
            delete(p);
        }
        else {
            q = p->next;
            p->next = q->next;
            delete(q);
        }
        return head;
    }
};