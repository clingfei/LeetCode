#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (int i = 0; i < nums.size(); ++i)
            nums_set.insert(nums[i]);
        int max = 0;
        int cur = 0;
        for (auto i : nums_set) {
            if (nums_set.find(i-1) == nums_set.end()) {
                cur = 1;
                int j = i + 1;
                while (nums_set.find(j++) != nums_set.end())
                    cur++;
                if (cur > max)
                    max = cur;
            }
        }
        return max;
    }
};