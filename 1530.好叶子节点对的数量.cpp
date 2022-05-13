/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
 */

// @lc code=start
#include <vector>
using namespace std;
// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        vector<int> left;
        vector<int> right;
        if (root == nullptr || root->left == nullptr && root->right == nullptr)  
            return res;
        if (root->left == nullptr) {
            dfs(root->right, right, distance, res);
        } else if (root->right == nullptr) {
            dfs(root->left, left, distance, res);
        } else {
            dfs(root->left, left, distance, res);
            dfs(root->right, right, distance, res);
            for (int i = 0; i < left.size(); ++i) {
                for (int j = 0; j < right.size(); ++j) {
                    if (left[i] + right[j] <= distance) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
    void dfs(TreeNode *root, vector<int>& tmp, const int distance, int& res) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            tmp.emplace_back(1);
            return;
        } else if (root->left == nullptr) {
            dfs(root->right, tmp, distance, res);
            for (auto &v:tmp) {
                v++;
            }
        } else if (root->right == nullptr) {
            dfs(root->left, tmp, distance, res);
            for (auto &v:tmp) {
                v++;
            }
        } else {
            vector<int> sleft;
            vector<int> sright;
            dfs(root->left, sleft,  distance, res);
            dfs(root->right, sright, distance, res);
            for (int i = 0; i < sleft.size(); ++i) {
                for (int j = 0; j < sright.size(); ++j) {
                    if (sleft[i] + sright[j] <= distance) {
                        res++;
                    }
                }
            }
            tmp.insert(tmp.end(), sleft.begin(), sleft.end());
            tmp.insert(tmp.end(), sright.begin(), sright.end());
            for (auto &v : tmp) {
                v++;
            }
        }
    }
};
// @lc code=end

