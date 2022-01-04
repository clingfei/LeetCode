#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> que;
        if (root == nullptr) return root;
        que.push(root);
        while (!que.empty()) {
            Node *prev = nullptr;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node *p = que.front();
                que.pop();
                if (prev != nullptr) 
                    prev->next = p;
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
                prev = p;
            }
            prev->next = nullptr;
        }
        return root;
    }
};