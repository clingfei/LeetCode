#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> umap;
        for (auto s:text) {
            umap[s]++;
        }
        int res = 0;
        while (true) {
            if (umap['b'] >=1 && umap['a'] >= 1 && umap['l'] >= 2 && umap['o'] >= 2 && umap['n'] >= 1) {
                res++;
                umap['b']--;
                umap['a']--;
                umap['l']-=2;
                umap['o']-=2;
                umap['n']--;
            }
            else break;
        }
        return res;
    }
};