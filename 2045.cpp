#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_map<int, int> fast;
    unordered_map<int, int> second;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        queue<pair<int, int>> Q; // (node, time)
        Q.push(make_pair(1, 0));
        unordered_map<int, vector<int>> G;
        int first = -1;
        
        for (auto edge: edges) {
            if (G.find(edge[0]) == G.end()) G[edge[0]] = vector<int>(0);
            if (G.find(edge[1]) == G.end()) G[edge[1]] = vector<int>(0);
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        
        while(!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            int node = p.first;
            int curTime = p.second;
            for (auto next: G[node]) {
                if (next == n) {
                    if (first == -1) {
                        first = curTime + time;
                    } else {
                        if (curTime + time > first) return curTime + time;
                    }
                }
                int targetTime = curTime + time;
                if ((targetTime / change) % 2 == 1) {
                    targetTime = (targetTime / change + 1) * change;
                }
                if (fast.find(next) == fast.end()) {
                    fast[next] = targetTime;
                    Q.push(make_pair(next, targetTime));                
                    continue;
                }
                if (second.find(next) == second.end() && fast[next] < targetTime) {
                    second[next] = targetTime;
                    Q.push(make_pair(next, targetTime));                
                    continue;
                }
            }
        }
        
        return -1;
    }
};