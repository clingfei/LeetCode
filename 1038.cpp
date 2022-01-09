struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        build(root);
        return root;
    }
    void build(TreeNode* root) {
        if (root == nullptr) return;
        build(root->right);
        sum += root->val;
        root->val = sum;
        build(root->left);
    }
};