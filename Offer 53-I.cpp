#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                cnt++;
        }
        return cnt;
    }
};