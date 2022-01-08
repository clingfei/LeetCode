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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* r = search(root, val);
        if (r->val > val) {
            TreeNode *p = new TreeNode(val);
            p->left = r->left;
            r->left = p;
        }
        else {
            TreeNode *p = new TreeNode(val);
            p->right = r->right;
            r->right = p;
        }
        return root;
    }
    TreeNode* search(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val > val) {
            if (root->left == nullptr)
                return root;
            else return search(root->left, val);
        }
        else {
            if(root->right == nullptr)
                return root;
            else 
                return search(root->right, val);
        }
            
    }
};