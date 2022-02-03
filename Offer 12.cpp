#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> isVisited(board.size(), vector<int> (board[0].size(), 0));
        queue<pair<int, int>> que;
        vector<pair<int, int>> temp;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    que.push(pair<int,int>{i, j});
                }
            }
        }
        if (que.size() == 0) return false;
        while (!que.empty()) {
            temp.push_back(que.front());
            isVisited[que.front().first][que.front().second] = 1;
            bool flag = backtracing(board, word, temp, isVisited, 1);
            if (flag) return true;
            isVisited[que.front().first][que.front().second] = 0;
            temp.pop_back();
            que.pop();
        }
        return false;
    }
    vector<pair<int, int>> dist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    bool backtracing(vector<vector<char>> &board, string word, vector<pair<int, int>> &temp, vector<vector<int>>&isVisited, int index) {
        if (index == word.size()) 
            return true;
        for (int i = 0; i < 4; ++i) {
            int x = temp.back().first + dist[i].first;
            int y = temp.back().second + dist[i].second;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && isVisited[x][y] == 0) {
                if (board[x][y] == word[index]) {
                    temp.push_back(pair<int, int>{x, y});
                    isVisited[x][y] = 1;
                    bool flag = backtracing(board, word, temp, isVisited, index + 1);
                    if (flag) return true;
                    isVisited[x][y] = 0;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
};