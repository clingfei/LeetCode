#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    static constexpr int BOUNDARY = 1000000;
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() < 2) {
            return true;
        }
        vector<int> rows, columns;
        for (const auto& pos: blocked) {
            rows.push_back(pos[0]);
            columns.push_back(pos[1]);
        }
        rows.push_back(source[0]);
        rows.push_back(target[0]);
        columns.push_back(source[1]);
        columns.push_back(target[1]);
        
        // 离散化
        sort(rows.begin(), rows.end());
        sort(columns.begin(), columns.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        columns.erase(unique(columns.begin(), columns.end()), columns.end());
        unordered_map<int, int> r_mapping, c_mapping;

        int r_id = (rows[0] == 0 ? 0 : 1);
        r_mapping[rows[0]] = r_id;
        for (int i = 1; i < rows.size(); ++i) {
            r_id += (rows[i] == rows[i - 1] + 1 ? 1 : 2);
            r_mapping[rows[i]] = r_id;
        }
        if (rows.back() != BOUNDARY - 1) {
            ++r_id;
        }

        int c_id = (columns[0] == 0 ? 0 : 1);
        c_mapping[columns[0]] = c_id;
        for (int i = 1; i < columns.size(); ++i) {
            c_id += (columns[i] == columns[i - 1] + 1 ? 1 : 2);
            c_mapping[columns[i]] = c_id;
        }
        if (columns.back() != BOUNDARY - 1) {
            ++c_id;
        }

        vector<vector<int>> grid(r_id + 1, vector<int>(c_id + 1));
        for (const auto& pos: blocked) {
            int x = pos[0], y = pos[1];
            grid[r_mapping[x]][c_mapping[y]] = 1;
        }
        
        int sx = r_mapping[source[0]], sy = c_mapping[source[1]];
        int tx = r_mapping[target[0]], ty = c_mapping[target[1]];

        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        grid[sx][sy] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if (nx >= 0 && nx <= r_id && ny >= 0 && ny <= c_id && grid[nx][ny] != 1) {
                    if (nx == tx && ny == ty) {
                        return true;
                    }
                    q.emplace(nx, ny);
                    grid[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};