#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        int h = 0;
        queue <Node *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node *p = que.front();
                que.pop();
                for (int j = 0; j < p->children.size(); ++j) {
                    if (p->children[j] != nullptr)
                        que.push(p->children[j]);
                }
            }
            h++;
        }
        return h;
    }
};