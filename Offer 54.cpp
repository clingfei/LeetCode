#define NULL 0
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        return inorder(root, k);
    }
    int inorder(TreeNode* root, int &k) {
        if (root == nullptr)
            return -1;
        int r = inorder(root->right, k);
        if (k == 0)
            return r;
        k--;
        if (k == 0) return root->val;
        return inorder(root->left, k); 
    }
};