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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr) return true;
        que.push(root);
        bool flag1 = false;
        while (!que.empty()) {
            if (flag1) return false;
            int size = que.size();
            bool flag =false;
            for (int i = 0; i < size; ++i) {
                TreeNode *p = que.front();
                que.pop();
                if (p->left == nullptr) {
                    flag = true;
                } else {
                    if (flag) return false;
                    que.push(p->left);
                }
                if (p->right == nullptr) {
                    flag = true;
                } else {
                    if (flag) return false;
                    que.push(p->right);
                }
            }
            if (flag1) {
                if (!que.empty()) return false;
            } 
            flag1 = flag;
        }
        return true;
    }
};