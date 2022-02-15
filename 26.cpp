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
    int prev;
    bool flag = false;
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return INT_MAX;
        
        int t = getMinimumDifference(root->left);
        if (flag == false) {
            prev = root->val;
            flag = true;
            return getMinimumDifference(root->right);
        }
        if (abs(root->val - prev) < t) 
            t = abs(root->val - prev);
        prev = root->val;
        int t1 = getMinimumDifference(root->right);
        if (t < t1) return t;
        else return t1;
    }   
};