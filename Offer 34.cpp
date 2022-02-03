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
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracing(root, res, temp, 0, target);
        return res;
    }
    void backtracing(TreeNode *root, vector<vector<int>> &res, vector<int> temp, int cur, const int target) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            if (cur + root->val == target) {
                temp.emplace_back(root->val);
                res.push_back(temp);
            }
        }
        else {
            cur += root->val;
            temp.push_back(root->val);
            backtracing(root->left, res, temp, cur, target);
            backtracing(root->right, res, temp, cur, target);
        }
    }
};