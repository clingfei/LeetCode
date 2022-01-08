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
    int freq = 0;
    vector<int> res;
    int curfreq = 0;
    int prev = 0;
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        if (curfreq == freq && freq != 0)
            res.push_back(prev);
        else if (curfreq > freq) {
            res.clear();
            res.push_back(prev);
            return res;
        }    
        return res;
    }
    void inorder(TreeNode *root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        if (prev == root->val)
            curfreq++;
        else {
            if (curfreq > freq) {
                res.clear();
                res.push_back(prev);
                freq = curfreq;
            }
            else if (curfreq == freq && freq != 0) 
                res.push_back(prev);
            
            curfreq = 1;
            prev = root->val;
        }
        inorder(root->right);
    }
};