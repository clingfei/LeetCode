#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (auto i:nums) {
            umap[i]++;
        }
        int res = 0;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            if (it->second == 1)
                res += it->first;
        }
        return res;
    }
};