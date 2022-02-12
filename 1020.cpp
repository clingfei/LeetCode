#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> dist = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    isVisited[i][j] = true;
                    continue;
                }
                else {
                    res++;
                    if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) {
                        que.push(pair<int, int>{i, j});
                        res--;
                        isVisited[i][j] = true;
                    }
                } 
            }
        }
        while (!que.empty()) {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dist[k].first;
                int y = j + dist[k].second;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !isVisited[x][y]) {
                    if (grid[x][y] == 1) {
                        que.push({x, y});
                        res--;
                    }
                    isVisited[x][y] = true;
                }
            }
        }
        return res;
    }
};