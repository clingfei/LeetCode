#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode*left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else if (left == nullptr || right == nullptr) {
            return false;
        }
        else if (left->val != right->val) {
            return false;
        }
        else {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
    }
};