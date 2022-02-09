#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res += umap[k + nums[i]]+ umap[nums[i] - k];
            umap[nums[i]]++;
        }
        return res;
    }
};