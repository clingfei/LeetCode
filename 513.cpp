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
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode *>q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            res = q.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);          
            }
        }
        return res;
    }
};