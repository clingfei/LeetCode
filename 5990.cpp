#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]]++;
        }       
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap[nums[i]] == 1 && umap.find(nums[i]+1) == umap.end() && umap.find(nums[i]-1) == umap.end())
                res.emplace_back(nums[i]);
        }
        return res;
    }
};