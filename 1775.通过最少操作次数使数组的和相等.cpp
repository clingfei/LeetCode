/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 *
 * https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/description/
 *
 * algorithms
 * Medium (48.92%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 14.7K
 * Testcase Example:  '[1,2,3,4,5,6]\n[1,1,2,2,2,2]'
 *
 * 给你两个长度可能不等的整数数组 nums1 和 nums2 。两个数组中的所有值都在 1 到 6 之间（包含 1 和 6）。
 * 
 * 每次操作中，你可以选择 任意 数组中的任意一个整数，将它变成 1 到 6 之间 任意 的值（包含 1 和 6）。
 * 
 * 请你返回使 nums1 中所有数的和与 nums2 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
 * 输出：3
 * 解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
 * - 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
 * - 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
 * - 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
 * 输出：-1
 * 解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [6,6], nums2 = [1]
 * 输出：3
 * 解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
 * - 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
 * - 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
 * - 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 10^5
 * 1 <= nums1[i], nums2[i] <= 6
 * 
 * 
 */
#include <vector>
#include <cmath>

using namespace std;
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        // 只要两个数组的
        if (6 * n < m || 6 * m < n) {
            return -1;
        }
        vector<int> cnt1(7, 0), cnt2(7, 0);
        int diff = 0;
        for (auto& i : nums1) {
            diff += i;
            ++cnt1[i];
        }
        for (auto& i : nums2) {
            diff -=i;
            ++cnt2[i];
        }
        if (diff == 0) {
            return 0;
        }
        if (diff < 0) {
            return help(cnt2, cnt1, -diff);
        } else {
            return help(cnt1, cnt2, diff);
        }
    }

    int help(vector<int> &cnt1, vector<int> &cnt2, int diff) {
        // cnt1[i]中保存的是值为i的个数
        // diff是两个数组之间的差值
        // 如何求出最小的操作数?
        // cnt1[i]对减小diff作出的贡献是 i - 1, cnt2做出的贡献是6 - i
        vector<int> cont(7, 0);
        for (int i = 1; i < 7; i++) {
            cont[i - 1] += cnt1[i];
            cont[6 - i] += cnt2[i];
        }
        int res = 0;
        for (int i = 5; i > 0 && diff > 0; i--) {
            // diff中有多少个5？
            int t = min((diff + i - 1)/ i, cont[i]);
            res += t;
            diff -= t * i;
        }
        return res;
    }
};
// @lc code=end

