#include <string>
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
    vector<string> res;
    string path;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return res;
        if (root ->left == nullptr && root->right == nullptr) {
            path += to_string(root->val);
            res.push_back(path);
            return res;
        }
        else {
            path += to_string(root->val) + "->"; 
            string path2 = path;
            binaryTreePaths(root->left);
            path = path2;
            binaryTreePaths(root->right);
            return res;
        }
    }
};