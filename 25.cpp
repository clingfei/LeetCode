#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *head1 = new ListNode();
        head1->next = head;
        ListNode *p = head1;
        ListNode *q = head1;
        while (p != nullptr && q != nullptr) {
            q = p;
            for (int i = 0; i < k && q != nullptr; ++i) {
                q = q->next;
            }
            if (q != nullptr) {
                p = reverse(p, q);
            } 
        }
        return head1->next;
    }
    ListNode* reverse(ListNode* start, ListNode* end) {
        if (start == end) return start;
        ListNode *t = end->next;
        vector<ListNode *> vec;
        ListNode *p = start->next;
        while (p != end) {
            vec.emplace_back(p);
            p = p->next;
        }
        vec.emplace_back(end);
        
        for (int i = vec.size()-2; i >= 0; --i) {
            vec[i+1]->next = vec[i];
        }
        start->next = vec.back();
        vec[0]->next = t;
        return vec[0];
    }
    
};