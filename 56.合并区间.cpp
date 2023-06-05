/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    1773
 * Dislikes: 0
 * Total Accepted:    574.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    static bool cmp(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0] || (v1[0] == v2 [0] && v1[1] < v2[1]);
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>>res;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
            } else {
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end

