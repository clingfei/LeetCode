#include <unordered_map>

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
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        if (umap.find(root) != umap.end()) 
            return umap[root];
        int val1 = root->val;
        if (root->left) val1+= rob(root->left->left) + rob(root->left->right);
        if (root->right) val1+= rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        umap[root] = max(val1, val2);
        return umap[root];
    }
};