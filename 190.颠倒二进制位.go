/*
 * @lc app=leetcode.cn id=190 lang=golang
 *
 * [190] 颠倒二进制位
 *
 * https://leetcode.cn/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (71.49%)
 * Likes:    582
 * Dislikes: 0
 * Total Accepted:    195.8K
 * Total Submissions: 273.6K
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * 颠倒给定的 32 位无符号整数的二进制位。
 * 
 * 提示：
 * 
 * 
 * 请注意，在某些语言（如
 * Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
 * 在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数
 * -1073741825。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 00000010100101000001111010011100
 * 输出：964176192 (00111001011110000010100101000000)
 * 解释：输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
 * ⁠    因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 11111111111111111111111111111101
 * 输出：3221225471 (10111111111111111111111111111111)
 * 解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
 * ⁠    因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入是一个长度为 32 的二进制字符串
 * 
 * 
 * 
 * 
 * 进阶: 如果多次调用这个函数，你将如何优化你的算法？
 * 
 */
package leetcode
// @lc code=start
const (
    m1 = 0x55555555 // 01010101010101010101010101010101
    m2 = 0x33333333 // 00110011001100110011001100110011
    m4 = 0x0f0f0f0f // 00001111000011110000111100001111
    m8 = 0x00ff00ff // 00000000111111110000000011111111
)

func reverseBits(n uint32) uint32 {
    n = n>>1&m1 | n&m1<<1
    n = n>>2&m2 | n&m2<<2
    n = n>>4&m4 | n&m4<<4
    n = n>>8&m8 | n&m8<<8
    return n>>16 | n<<16
}
// @lc code=end

