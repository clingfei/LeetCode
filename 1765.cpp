#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> que; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    que.push(pair<int, int>(i, j));
                }
            }
        }
        while (!que.empty()) {
            auto &p = que.front();
            for (auto &dir:dirs) {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (0 <= x && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                    ans[x][y] = ans[p.first][p.second] + 1;
                    que.push(pair<int, int>(x, y));
                }
            }
            que.pop();
        }
        return ans;
    }
};