#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p = head, *q = head;
        for (int i = 0; i < k; ++i) 
            q = q->next;
        while (q != nullptr) {
            q = q->next;
            p = p->next;
        }
        return p;
    }
};