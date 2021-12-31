struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head, *q = head->next;
        ListNode *prev = nullptr;
        head = q;
        while (p != nullptr && q != nullptr) {
            if (prev == nullptr) {
                ListNode *t = q->next;
                q->next = p;
                p->next = t;
                prev = p;
                p = t;
                if (p != nullptr) q = p->next;
            }
            else {
                prev->next = q;
                ListNode *t = q->next;
                q->next = p;
                p->next = t;
                prev = p;
                p = t;
                if (p != nullptr) q = p->next;
            }
        }
        return head;
    }
};