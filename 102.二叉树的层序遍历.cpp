/*
@lc app=leetcode.cn id=102 lang=cpp
 *
[102] 二叉树的层序遍历
 *
https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
algorithms
Medium (65.33%)
Likes:    1545
Dislikes: 0
Total Accepted:    730K
Total Submissions: 1.1M
Testcase Example:  '[3,9,20,null,null,15,7]'
 *
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。



示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  res;
        queue<TreeNode *> temp;
        if (root == nullptr) return res;
        temp.push(root);
        while (!temp.empty()) {
            vector<int> tmp;
            int size = temp.size();
            for (int i = 0; i < size; i++) {
                auto p = temp.front();
                temp.pop();
                tmp.push_back(p->val);
                if (p->left) temp.push(p->left);
                if (p->right) temp.push(p->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

