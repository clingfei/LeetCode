#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int h = 0;
        if (root == nullptr) return h;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int s = que.size();
            for (int i = 0; i < s; ++i) {
                TreeNode *p = que.front();
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            h++;
        }
        return h;
    }
};