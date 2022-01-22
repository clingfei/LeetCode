#include <vector>
#include <queue>
using namespace std; 


class Solution {
private:
    struct elem {
        int price;
        int row;
        int col;
    };
    static bool cmp (elem a, elem b) {
        return a.price < b.price || a.price == b.price && a.row < b.row || a.price == b.price && a.row == b.row && a.col < b.col;
    }
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> res;
        vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<vector<int>> que;
        que.push(start);
        
        while (!que.empty() && res.size() < k) {
            int size = que.size();
            vector<elem> temp;
            for (int i = 0; i < size; ++i) {
                vector<int> p = que.front();
                int row = p[0], col = p[1];
                
                que.pop();
                if (isVisited[row][col] == 1) continue;
                isVisited[row][col] = 1;
                if (grid[row][col] != 1 && grid[row][col] >= pricing[0] && grid[row][col] <= pricing[1]) {
                    elem t;
                    t.price = grid[row][col];
                    t.row = row;
                    t.col = col;
                    temp.emplace_back(t);
                }
                if (row - 1 >= 0) {
                    if (grid[row-1][col] != 0 && isVisited[row-1][col] == 0) {
                        que.push({row-1, col});
                    }
                }
                if (row + 1 < grid.size()) {
                    if (grid[row+1][col] != 0 && isVisited[row+1][col] == 0) {
                        que.push({row+1, col});
                    }
                }
                if (col - 1 >= 0) {
                    if (grid[row][col-1] != 0 && isVisited[row][col-1] == 0) {
                        que.push({row, col-1});
                    }
                }
                if (col + 1 < grid[0].size()) {
                    if (grid[row][col+1] != 0 && isVisited[row][col+1] == 0) {
                        que.push({row, col+1});
                    }
                }
            }
            sort(temp.begin(), temp.end(), cmp);
            size = res.size();
            int i = size;
            while (res.size() < k && i - size < temp.size()) {
                res.push_back({temp[i-size].row, temp[i-size].col});
                ++i;
            } 
            if (res.size() == k) break;
        }
        return res;
    }
};