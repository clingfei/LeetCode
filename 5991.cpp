#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) pos.emplace_back(nums[i]);
            else neg.emplace_back(nums[i]);
        }
        int i = 0;
        int j = 0; 
        while (i < nums.size()) {
            nums[i++] = pos[j];
            nums[i++] = neg[j++]; 
        }
        return nums;
    }
};