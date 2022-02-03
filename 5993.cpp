#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); ++i) {
            uset.insert(nums[i]);
        }
        while (uset.find(original) != uset.end()) {
            original *= 2;
        }
        return original;
    }
};