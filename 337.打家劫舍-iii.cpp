/*
@lc app=leetcode.cn id=337 lang=cpp
 *
[337] 打家劫舍 III
 *
https://leetcode.cn/problems/house-robber-iii/description/
 *
algorithms
Medium (60.96%)
Likes:    1489
Dislikes: 0
Total Accepted:    237.3K
Total Submissions: 389.2K
Testcase Example:  '[3,2,3,null,3,null,1]'
 *
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。



示例 1:




输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7

示例 2:




输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9




提示：




树的节点数在 [1, 10^4] 范围内
0 <= Node.val <= 10^4


 */
#include <vector>
#include <unordered_map>
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
private: 
    unordered_map<TreeNode *, int> umap;
public:
    int rob(TreeNode* root) {
        // 返回值0表示root没有偷，返回值1表示root偷了
        // 返回对应的最大值。
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if (umap.find(root) != umap.end()) return umap[root];
        int val1 = root->val;
        if (root->left != nullptr)
            val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right != nullptr)
            val1 += rob(root->right->left) + rob(root->right->right);
        int val2 = rob(root->left) + rob(root->right);
        umap[root] = max(val1, val2);
        return max(val1, val2);
    }
};
// @lc code=end

