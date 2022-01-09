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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key && root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->val == key && root->left == nullptr) {
            TreeNode *p = root->right;
            delete root;
            return p;
        }
        if (root->val == key && root->right == nullptr) {
            TreeNode *p = root->left;
            delete root;
            return p;
        }
        if (root->val == key) {
            TreeNode *p = root->right;
            while (p->left != nullptr)
                p = p->left;
            p->left = root->left;
            p = root->right;
            delete root;
            return p;
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

};