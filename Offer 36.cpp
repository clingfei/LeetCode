#define NULL 0
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:    
    queue<Node *> que;
public:
    Node* treeToDoublyList(Node* root) {
        inorder(root);
        Node *head = que.front();
        que.pop();
        Node *pre;
        pre = head;
        while (!que.empty()) {
            pre->right = que.front();
            que.front()->left = pre;
            que.pop();
            pre = pre->right;
        }
        head->left = pre;
        pre->right = head;
        
    }
    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        que.push(root);
        inorder(root->right);
    }
};