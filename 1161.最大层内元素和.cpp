/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 */

// @lc code=start
#include <queue>
using namespace std;
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> que;
        que.push(root);
        int max = root->val, res = 1;
        int index = 1;
        while (!que.empty()) {
            int size = que.size();
            int cur = 0;
            for (int i = 0; i < size; i++) {
                auto p = que.front();
                que.pop();
                cur += p->val;
                if (p->left != nullptr) que.push(p->left);
                if (p->right != nullptr) que.push(p->right);
            }
            if (cur > max) {
                max = cur;
                res = index;
            }
            index++;
        }
        return res;
    }
};
// @lc code=end

