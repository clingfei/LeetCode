#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *root1 = new TreeNode(root->val);
        root1->left = mirrorTree(root->right);
        root1->right = mirrorTree(root->left);
        return root1;
    }
};