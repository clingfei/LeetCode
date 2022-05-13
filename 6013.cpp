struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode*head1 = new ListNode();
        head1->next = new ListNode(0);
        ListNode *p = head, *q = p;
        ListNode *p1 = head1;
        while (p != nullptr) {
            if (p->val == 0)
                p = p->next;
            else {
                p1 = p1->next;
                p1->val += p->val;
                q = p->next;
                while (q != nullptr && q->val != 0) {
                    p1->val += q->val;
                    q = q->next;
                }
                if (q == nullptr)
                    break;
                else {
                    p = q->next;
                    p1->next = new ListNode(0);
                }
            }
        }
        p1->next = nullptr;
        return head1->next;
    }
};