#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) return root;
        TreeNode *p1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *p2 = lowestCommonAncestor(root->right, p, q);
        if (p1 == NULL && p2 == NULL)   return nullptr;
        if ((p1 == p && p2 == q) || (p1 == q && p2 == p)) return root;
        if (p1 == nullptr) return p2;
        if (p2 == nullptr) return p1;
        return root;  
    }
};