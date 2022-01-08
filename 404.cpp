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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) 
            return sum;
        if (root->left == nullptr && root->right == nullptr) 
            return sum;
        calc(root->left, 1);
        calc(root->right, 0);
        return sum;
    }
    void calc(TreeNode* root, int flag) {
        if (root->left == nullptr && root->right == nullptr) {
            if (flag == 1)
                sum += root->val;
            return;
        }
        if (root->left != nullptr)
            calc(root->left, 1);
        if (root->right != nullptr)
            calc(root->right, 0);
    }
};