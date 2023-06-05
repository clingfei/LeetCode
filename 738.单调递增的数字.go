/*
 * @lc app=leetcode.cn id=738 lang=golang
 *
 * [738] 单调递增的数字
 *
 * https://leetcode.cn/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (50.31%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    78.3K
 * Total Submissions: 155.6K
 * Testcase Example:  '10'
 *
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 * 
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 10
 * 输出: 9
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 1234
 * 输出: 1234
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: n = 332
 * 输出: 299
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */
package leetcode
// @lc code=start
func monotoneIncreasingDigits(N int) int {
    s := strconv.Itoa(N)//将数字转为字符串，方便使用下标
    ss := []byte(s)//将字符串转为byte数组，方便更改。
    n := len(ss)
    if n <= 1 {
        return N
    }
    for i := n-1; i > 0; i-- {
        if ss[i-1] > ss[i] {   //前一个大于后一位,前一位减1，后面的全部置为9
            ss[i-1] -= 1
            for j := i; j < n; j++ {   //后面的全部置为9
                ss[j] = '9'
            }
        } 
    }
    res, _ := strconv.Atoi(string(ss))
    return res 
}
// @lc code=end

