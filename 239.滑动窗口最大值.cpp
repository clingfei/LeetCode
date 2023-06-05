/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.94%)
 * Likes:    2031
 * Dislikes: 0
 * Total Accepted:    385.8K
 * Total Submissions: 772.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res; 
        deque<int> que;
        for (int i = 0; i < k; i++) {
            while (!que.empty() && que.back() < nums[i])
                que.pop_back();
            que.push_back(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            if (que.front() == nums[i - k])
                que.pop_front();
            while (!que.empty() && que.back() < nums[i])
                que.pop_back();
            que.push_back(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end

