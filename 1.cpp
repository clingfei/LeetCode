#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mmap;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = mmap.find(target - nums[i]);
            if (iter != mmap.end()) 
                return {iter->second, i};
            mmap[nums[i]] = i;
        }
        return res;
    }
};