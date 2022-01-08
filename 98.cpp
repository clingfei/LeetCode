#include <vector>

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
private:
    int prev = INT_MIN;
    bool f = false;
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool flag = isValidBST(root->left);
        if (flag == false) return false;
        if (root->val > prev) {
            f = true;
            prev = root->val;
            return isValidBST(root->right);
        }
        else if (f) return false;
        else {
            f = true;
            prev = root->val;
            return isValidBST(root->right);
        }
    }
};