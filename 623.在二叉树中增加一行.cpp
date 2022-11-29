/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */
#include <queue>
using  namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *nroot = new TreeNode(val, root, nullptr);
            return nroot;
        }
        queue<TreeNode *> que;
        que.push(root);
        int curdepth = 1;
        while (!que.empty() && curdepth < depth - 1) {
            int size = que.size();
            for (int i = 0; i < size; i ++) {
                auto t = que.front();
                que.pop();
                if (t->left) que.push(t->left);
                if (t->right) que.push(t->right);
            }
            curdepth++;
        }
        while (!que.empty()) {
            auto t = que.front();
            t->left = new TreeNode(val, t->left, nullptr);
            t->right = new TreeNode(val, nullptr, t->right);
            que.pop();
        }
        return root;
    }
};
// @lc code=end

