/*
 * @lc app=leetcode.cn id=1442 lang=golang
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */
package leetcode
// @lc code=start
func countTriplets(arr []int) int {
	prefix := make([]int, len(arr))
	i := 0
	res := 0
	prefix[i] = arr[0]
	for i = 1; i < len(arr); i++ {
		prefix[i] = prefix[i - 1] ^ arr[i]
	}
	for i := 0; i < len(arr); i++ {
			for k := i + 1; k < len(arr); k++ {
				if i == 0 {
					if prefix[k] == 0 {
						res += k - i
					}
				} else {
					if prefix[k] ^ prefix[i - 1] == 0 {
						res += k - i
					}
				}
			}
	}
	return res
}
// @lc code=end

