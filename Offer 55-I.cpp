#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *>que;
        if (root == nullptr) return 0;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            res++;
            for (int i = 0; i < size; ++i) {
                TreeNode *p = que.front();
                que.pop();
                if (p->left != nullptr) que.push(p->left);
                if (p->right != nullptr) que.push(p->right);
            } 
        }
        return res;
    }
};