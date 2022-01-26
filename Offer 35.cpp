#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> umap;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        if (umap.find(head) == umap.end()) {
            Node *newhead = new Node(head->val);
            umap[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return umap[head];
    }
};