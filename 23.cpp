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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* p = new ListNode();
        ListNode* r = p;

        while(true) {
            int min = INT_MAX;
            int index = 0;
            bool flag = false;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == nullptr) continue;
                else {
                    flag = true;
                    if (lists[i]->val < min) {
                        index = i;
                        min = lists[i]->val;
                    }
                }
            }
            if (!flag) break;
            r->next = new ListNode(min);
            lists[index] = lists[index]->next; 
        }        
        return p->next;
    }

};