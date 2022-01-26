#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head;
        ListNode *q = head->next;
        while (p != nullptr && q != nullptr) {
            ListNode *temp = q->next;
            q -> next = p;
            p = q;
            q = temp;
        }
        head->next = nullptr;
        head = p;
        return head;
    }
};