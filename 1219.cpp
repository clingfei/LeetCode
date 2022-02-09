#include <vector>

using namespace std;

class Solution {
    int max = 0;
    vector<pair<int, int>> dist = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) continue;
                isVisited[i][j] = 1;
                if (grid[i][j] > max) max = grid[i][j];
                backtracing(isVisited, grid, pair<int,int>{i, j}, grid[i][j]);
                isVisited[i][j] = 0;
            }
        }
        return max;
    }
    void backtracing(vector<vector<int>>&isVisited, vector<vector<int>> &grid, pair<int, int> cur, int sum) {
        for (int i = 0; i < 4; ++i) {
            int x = cur.first + dist[i].first;
            int y = cur.second + dist[i].second;
            if (x >=0 && x < grid.size() && y >= 0 && y < grid[0].size() && isVisited[x][y] != 1) {
                if (grid[x][y] != 0) {
                    sum += grid[x][y];
                    isVisited[x][y] = 1;
                    if (sum > max) max = sum;
                    backtracing(isVisited, grid, pair<int, int>({x, y}), sum);
                    isVisited[x][y] = 0;
                    sum -= grid[x][y];
                }
            }
        } 

    }
};