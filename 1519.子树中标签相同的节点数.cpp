/*
 * @lc app=leetcode.cn id=1519 lang=cpp
 *
 * [1519] 子树中标签相同的节点数
 */
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start

class Solution {
private:
    vector<vector<int>> g;
    vector<vector<int>> f;
    vector<bool> isVisited;
public:
    void dfs(int starter, int pre, const string &labels) {
        f[starter][labels[starter] - 'a']  = 1;

        isVisited[starter] = true;
        for (int i = 0; i < g[starter].size(); ++i) {
            if (g[starter][i] == pre) 
                continue;
            dfs(g[starter][i], starter, labels);
            for (int j = 0; j < 26; ++j) {
                f[starter][j] += f[g[starter][i]][j];
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n);
        //为了初始化一个图，可以通过一个下标访问到与之直接相连的所有的节点
        for(auto edge:edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        isVisited.assign(n, 0);
        f.assign(n, vector<int>(26));
        vector<int> res(n, 0);
        dfs(0, -1, labels);
        for (int i = 0; i < n; ++i) {
            res[i] = f[i][labels[i]-'a'];
        }
        return res;
    }
};
// @lc code=end

