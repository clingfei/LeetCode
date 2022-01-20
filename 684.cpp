#include <vector>

using namespace std;

class Solution {
private:
    int father[1005];
    void init() {
        for (int i = 0; i < 1005; ++i)
            father[i] = i;
    }
    
    int find(int i) {
        if (i == father[i])
            return i;
        else 
            return find(father[i]);
    }

    void join(int i1, int i2) {
        int r1 = find (i2);
        father[r1] = i1;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < edges.size(); ++i) {
            int u1 = find(edges[i][0]);
            int u2 = find(edges[i][1]);
            if (u1 == u2) 
                return edges[i];
            join(u1, u2);
        }
        return vector<int>(2, 0);
    }
};