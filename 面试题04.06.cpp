#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode * res = nullptr, * prev = nullptr;
        inorderTraversal(root, prev, p, res);
        return res;
    }
    void inorderTraversal(TreeNode * root, TreeNode*& prev, TreeNode *p, TreeNode*& res ){
        if(root == nullptr || res != nullptr) return;
        inorderTraversal(root->left, prev, p, res);
        if(prev == p) res = root;
        prev = root;
        inorderTraversal(root->right, prev, p, res);
    }
};