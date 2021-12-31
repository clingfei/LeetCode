struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = nullptr, *q = head;
        while (q != nullptr) {
            if (q->val == val) {
                if (p == nullptr) {
                    ListNode *tmp = head;
                    head = q->next;
                    q = q->next;
                    delete(tmp);
                }
                else {
                    ListNode *tmp = q;
                    p->next = q->next;
                    q = p->next;
                    delete(tmp);
                }
            }
            else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};