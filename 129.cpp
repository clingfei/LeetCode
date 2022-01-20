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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        if (root->left) res += sum(root->left, root->val);
        if (root->right) res += sum(root->right, root->val);
        if (root->left== nullptr && root->right == nullptr)
            return root->val;
        return res;
    }

    int sum(TreeNode* root, int father) {
        int res = 0; 
        if (root->left == nullptr && root->right == nullptr)
            return father * 10 + root->val;
        if (root->left) res += sum(root->left, father * 10 +root->val);
        if (root->right) res += sum(root->right, father * 10 + root->val);
      
        return res; 
    }
};