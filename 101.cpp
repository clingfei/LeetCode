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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        else if (left == nullptr || right == nullptr)
            return false;
        else if (left->val != right->val)
            return false;
        else {
            return symmetric(left->right, right->left) && symmetric(left->left, right->right);
        }
    }
};