/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode.cn/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (72.12%)
 * Likes:    606
 * Dislikes: 0
 * Total Accepted:    223.6K
 * Total Submissions: 310K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 * 
 * 
 * 只使用数字1到9
 * 每个数字 最多使用一次 
 * 
 * 
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 解释:
 * 1 + 2 + 4 = 7
 * 没有其他符合的组合了。
 * 
 * 示例 2:
 * 
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 解释:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * 没有其他符合的组合了。
 * 
 * 示例 3:
 * 
 * 
 * 输入: k = 4, n = 1
 * 输出: []
 * 解释: 不存在有效的组合。
 * 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= k <= 9
 * 1 <= n <= 60
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    void backtracing(vector<vector<int>>& res, vector<int> path, int cur, int target, int k, int last) {
        if (path.size() == k) {
            if (cur == target)
                res.emplace_back(path);
            return;
        }
        for (int i = last + 1; i <= 9; i++) {
            cur += i;
            path.emplace_back(i);
            backtracing(res, path, cur, target, k, i);
            path.pop_back();
            cur -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        backtracing(res, path, 0, n, k, 0);
        return res;
    }
};
// @lc code=end

