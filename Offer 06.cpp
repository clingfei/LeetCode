#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode *p = head;
        while (p != nullptr) {
            res.emplace_back(p->val);
            p = p->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
