#define NULL 0
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        int pl = 0, ph = preorder.size() - 1;
        int il = 0, ih = inorder.size() - 1;
        int mid = 0;
        for (int i = 0; i < inorder.size(); ++i) 
            if (inorder[i] == preorder[pl]) {
                mid = i;
                break;
            }
        int ls = mid - il;
        root->left = build(preorder, pl + 1, pl + ls, inorder, il, mid - 1);
        root->right = build(preorder, pl + mid + 1, ph, inorder, mid + 1, ih);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int pl, int ph, vector<int>& inorder, int il, int ih) {
        if (pl > ph) return nullptr;
        if (pl == ph) {
            TreeNode *t = new TreeNode(preorder[pl]);
            t->left = nullptr;
            t->right = nullptr;
            return t;
        } else {
            int mid = 0;
            for (int i = il; i <= ih; ++i) {
                if (inorder[i] == preorder[pl]) {
                    mid = i;
                    break;
                }
            }
            TreeNode *root = new TreeNode(preorder[pl]);
            int ls = mid - il;
            root->left = build(preorder, pl + 1, pl + ls, inorder, il, mid-1);
            root->right = build(preorder, pl + ls + 1, ph, inorder, mid + 1, ih);
            return root;
        }
    }
};