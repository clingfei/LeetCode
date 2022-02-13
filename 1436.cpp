#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> umap;
        for (auto u : paths) {
            umap.insert({u[0], u[1]});
        }
        for (auto u : paths) {
            if (umap.find(u[1]) == umap.end())
                return u[1];
        }
        return "";
    }
};