#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]].emplace_back(i);
        }        
        int res = 0;
        for (auto vec : umap) {
            for (int i = 0; i < vec.second.size(); ++i) {
                for (int j = i + 1; j < vec.second.size(); ++j) {
                    if ((vec.second[i] * vec.second[j]) % k == 0)
                        res++; 
                }
            }
        }
        return res;
    }
};