#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (B == nullptr && A != nullptr)
            return false;
        if (A->val == B->val) 
            return (isSub(A->left, B->left) && isSub(A->right, B->right)) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        else 
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool isSub(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        else if (A == nullptr) 
            return false;
        if (A->val == B->val) {
            return (isSub(A->left, B->left) && isSub(A->right, B->right));
        }
    }
};