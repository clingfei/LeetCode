/*
 * @lc app=leetcode.cn id=179 lang=golang
 *
 * [179] 最大数
 *
 * https://leetcode.cn/problems/largest-number/description/
 *
 * algorithms
 * Medium (41.20%)
 * Likes:    1062
 * Dislikes: 0
 * Total Accepted:    184.5K
 * Total Submissions: 447.9K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 *
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [10,2]
 * 输出："210"
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= Nums.length <= 100
 * 0 <= Nums[i] <= 10^9
 *
 *
 */
package leetcode

import (
	"sort"
	"strconv"
)

// @lc code=start

type Nums []int

func (s Nums) Len() int {
	return len(s)
}

func (s Nums) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s Nums) Less(i, j int) bool {
	s1 := strconv.Itoa(s[i])
	s2 := strconv.Itoa(s[j])
	return s1 + s2 > s2 + s1
}

func largestNumber(nums []int) string {
	// 排序
	// 高位数字越大最终的数字越大
	// 如何处理长度不一致的数字？
	sort.Sort(Nums(nums))
	res := ""
	for _, v := range nums {
		res += strconv.Itoa(v)
	}
	i:= 0
	for ; i < len(res) - 1 && res[i] == '0'; i++ {}
	res = res[i:]
	return res
}
// @lc code=end

