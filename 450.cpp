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
        TreeNode *t = find(root, key);
        if (t->left != nullptr && t->left->val == key) {
            if (t->left->left != nullptr) {
                
            }
        }
    }
    TreeNode* find(TreeNode * root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val < key) {
            if (root->right->val == key)
                return root;
            return find(root->right, key);
        }
        if (root->val > key) {
            if (root->left->val == key)
                return root;
            return find(root->left, key);
        }
        if (root->val == key)
            return root;
    }
};