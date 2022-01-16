#include <vector>
#include <random>
#include <ctime>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode *p;
public:
    Solution(ListNode* head) {
        p = head;
    }
    
    int getRandom() {
        int ans = 0;
        int idx = 0;
        ListNode *q = p;
        while (q!=nullptr) {
            if (rand() % idx == 0) ans = q->val;
            q = q->next;
            idx++;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */