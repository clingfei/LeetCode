#include <vector>

using namespace std;

class Solution {
private:
    vector<pair<int,int>> dist = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};
    static vector<vector<vector<int>>> visited;
public:
    double knightProbability(int n, int k, int row, int column) {
        visited = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int> (k + 1, 0)));
        int x = row, y = column;
        int cnt = 0;
        if (k == 0) {
            if (row >= 0 && row < n && column >= 0 && column < n) 
                return 1.0;
            else return 0.0;
        }
        for (int i = 0; i < dist.size(); ++i) {
            x += dist[i].first;
            y += dist[i].second;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                backtracing(n, k, x, y, 1, cnt);
            } 
            x -= dist[i].first;
            y -= dist[i].second;
        }
        return cnt / pow(8, k);
    }
    void backtracing(int n, int k, int x, int y, int cur, int &cnt) {
        if (cur >= k) {
            cnt++;
            visited[x][y][k] = visited[x][y][k]/8 + 1 / ;  
            return;
        }
        for (int i = 0; i < dist.size(); ++i) {
            x += dist[i].first;
            y += dist[i].second;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                backtracing(n, k, x, y, cur+1, cnt);
            } 
            x -= dist[i].first;
            y -= dist[i].second;
        }
    }
};