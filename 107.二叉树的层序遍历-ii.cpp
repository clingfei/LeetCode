/*
@lc app=leetcode.cn id=107 lang=cpp
 *
[107] 二叉树的层序遍历 II
 *
https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
 *
algorithms
Medium (72.15%)
Likes:    641
Dislikes: 0
Total Accepted:    250.8K
Total Submissions: 347.6K
Testcase Example:  '[3,9,20,null,null,15,7]'
 *
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）



示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]


示例 2：


输入：root = [1]
输出：[[1]]


示例 3：


输入：root = []
输出：[]




提示：


树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000


 */
#include <vector>
#include <queue>
using namespace std;
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
Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> que;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                auto p = que.front();
                que.pop();
                tmp.push_back(p->val);
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

