#include <iostream>
#include <vector>

using namespace std;

int divide(vector<int> &vec, int low, int high) {
    int pivot = vec[low];
    while(low < high) {
        while (vec[high] > pivot && low < high) {high--;}
        if (low < high) {int temp = vec[high]; vec[high] = vec[low]; vec[low] = temp;}
        while (vec[low] < pivot && low < high) {low++;}
        if (low < high) {int temp = vec[high]; vec[high] = vec[low]; vec[low] = temp;}
    } 
    vec[low] = pivot;
    return low;
}
void sort(vector<int> &vec, int low, int high) {
    if (low >= high) return;
    int mid = divide(vec, low, high);
    sort(vec, low, mid-1);
    sort(vec, mid+1, high);
}


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = reverse(l1);
        ListNode *head2 = reverse(l2);
        int add = 0;
        ListNode *head = nullptr;
        ListNode *p1 = head1, *p2 = head2;
        while (p1 != nullptr && p2!=nullptr) {
            ListNode *p = new ListNode((p1->val + p2->val + add) % 10);
            add = (p1->val + p2->val + add) / 10;
            p->next = head;
            head = p;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != nullptr) {
            ListNode *p = new ListNode((p1->val + add) % 10);
            add = (p1->val + add) / 10;
            p->next = head;
            head = p;
            p1 = p1->next; 
        }
        while (p2 != nullptr) {
            ListNode *p = new ListNode((p2->val + add) % 10);
            add = (p2->val + add) / 10;
            p->next = head;
            head = p;
            p2 = p2->next;
        }
        if (add != 0) {
            ListNode *p = new ListNode(add);
            p->next = head;
            head = p;
        }
        return head;
    }
    ListNode* reverse(ListNode* l) {
        if (l == nullptr || l->next == nullptr) 
            return l;
        ListNode *p = l, *q = l->next;
        while (p!= nullptr || q != nullptr) {
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        l->next = nullptr;
        return p;
    }
};

