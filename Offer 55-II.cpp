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
    bool isBalanced(TreeNode* root) {
        int lh = 0;
        int rh = 0;
        bool lt = isBalanced(root->left, lh);
        bool rt = isBalanced(root->right, rh);
        return lt && rt && abs(lh - rh) <= 1;
    }
    bool isBalanced(TreeNode* root, int &height) {
        if (root == nullptr) {
            height = 0;
            return true;
        }
        int lh = 0;
        int rh = 0;
        bool lt = isBalanced(root->left, lh);
        bool rt = isBalanced(root->right, rh);
        height = max(lh, rh) + 1;
        return lt && rt && abs(lh - rh) <= 1;
    }
};