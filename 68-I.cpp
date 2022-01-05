#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *p1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *p2 = lowestCommonAncestor(root->right, p, q);
        if (p1 == nullptr && p2 == nullptr) return nullptr;
        if ((p1 == p && p2 == q) || (p1 == q && p2 == p))           //root是公共子节点 
            return root;
        if (p1 == nullptr)                                          //p2是公共子节点
            return p2;
        if (p2 == nullptr)                                          //p1是公共子节点
            return p1;
        return root;
    }
};