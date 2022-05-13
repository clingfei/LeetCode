#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> umap;
        umap[0] = -1;
        int max = 0;
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i] == 1 ? 1 : -1;
            if (umap.find(pre) != umap.end()) {
                if (i - umap[pre] > max)
                    max = i - umap[pre];
            }
            if (umap.find(pre) == umap.end())
                umap[pre] = i;
        }
        return max;
    }
};