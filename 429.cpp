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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<Node *>que;
        que.push(root);
        while (!que.empty()) {
            int s = que.size();
            vector<int> tmp;
            for (int i = 0; i < s; ++i) {
                Node *p = que.front();
                que.pop();
                tmp.push_back(p->val);
                for (int j = 0; j < p->children.size(); ++j) {
                    if (p->children[j]) que.push(p->children[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};