/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.27%)
 * Likes:    1246
 * Dislikes: 0
 * Total Accepted:    469.7K
 * Total Submissions: 607.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int> &path, int n, int k, int startIndex) {
        if (path.size() == k) {
            vector<int> tmp(path.begin(), path.end());
            res.push_back(tmp);
            return;
        }
        for (int i = startIndex; i <= n - k + 1 + path.size(); i++) {
            path.emplace_back(i);
            dfs(res, path, n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, n, k, 1);
        return res;
    }
};
// @lc code=end

