/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.25%)
 * Likes:    1202
 * Dislikes: 0
 * Total Accepted:    382.6K
 * Total Submissions: 635.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    void backtracing(vector<vector<int>> &res, vector<int>& candidates, vector<int> path, int idx, int target, int cur) {
        for (int i = idx; i < candidates.size() && cur <= target; i++) {
            cur += candidates[i];
            path.emplace_back(candidates[i]);
            if (cur == target) {
                res.emplace_back(path);
            } else {
                backtracing(res, candidates, path, i + 1, target, cur);
            }
            path.pop_back();
            cur -= candidates[i];  
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
                i++;
            } 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtracing(res, candidates, path, 0, target, 0);
        return res;
    }
};
// @lc code=end

