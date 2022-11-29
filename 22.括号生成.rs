/*
 * @lc app=leetcode.cn id=22 lang=rust
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.54%)
 * Likes:    2983
 * Dislikes: 0
 * Total Accepted:    622.8K
 * Total Submissions: 803.2K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut dp: std::collections::HashMap<i32, Vec<String>> = std::collections::HashMap::new();
        dp.insert(1, vec!{"()".to_string()});
        dp.insert(2, vec!{"()()".to_string(), "(())".to_string()});
        let mut i = 3;
        while i <= n {
            let vec = dp.entry(i).or_insert(vec![]);
            for str in dp.entry(i - 1).or_default() {
                vec.push("()".to_string() + str.clone());
            }
            for str in dp.entry(i - 1).or_default() {
                vec.push("(".to_string() + str + ")");
            }
            let mut j = 1;
            while j < i {
                for v in dp.entry(j).or_default()  {
                    for v1 in dp.entry(i - j - 1).or_default() {
                        vec.push("(".to_string() + v + ")" + v1);
                    }
                }
            }
        }
        return dp.entry(n).or_insert(vec![]).to_owned();
    }
}
// @lc code=end

