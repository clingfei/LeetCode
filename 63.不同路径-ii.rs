/*
 * @lc app=leetcode.cn id=63 lang=rust
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (40.84%)
 * Likes:    918
 * Dislikes: 0
 * Total Accepted:    321.5K
 * Total Submissions: 787.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let mut vec = vec![vec![0; obstacle_grid[0].len()]; obstacle_grid.len()];
        if obstacle_grid[0][0] != 1 {
            vec[0][0] = 1;
        }
        for i in 1.. obstacle_grid[0].len() {
            if obstacle_grid[0][i] != 1 {
                vec[0][i] = vec[0][i - 1];
            }
        }
        for i in 1 .. obstacle_grid.len() {
            if obstacle_grid[i][0] != 1 {
                vec[i][0] = vec[i - 1][0];
            }
        }
        for i in 1 .. obstacle_grid.len() {
            for j in 1 .. obstacle_grid[0].len() {
                if obstacle_grid[i][j] != 1 {
                    vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
                }
            }
        }
        vec[obstacle_grid.len() - 1][obstacle_grid[0].len() - 1]
    }
}
// @lc code=end

