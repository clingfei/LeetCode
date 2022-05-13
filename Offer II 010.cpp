#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = 1;
        int pre = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            if (umap.find(pre - k) != umap.end())
                res += umap[pre - k];
            umap[pre]++;
        }
        return res;
    }
};