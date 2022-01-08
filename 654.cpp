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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int index =0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[index])
                index = i;
        }
        TreeNode *root = new TreeNode(nums[index]);
        root->left = construct(nums, 0, index);
        root->right = construct(nums, index+1, nums.size());   
        return root;
    }
    TreeNode * construct(vector<int> &nums, int l, int r) {
        if (l >= r || l >= nums.size()) return nullptr;
        int index = l;
        for (int i = l; i < r && i < nums.size(); ++i) {
            if (nums[i] > nums[index])
                index = i;
        }
        TreeNode *root = new TreeNode(nums[index]);
        root->left = construct(nums, l, index);
        root->right = construct(nums, index+1, r);   
        return root;
    }
};