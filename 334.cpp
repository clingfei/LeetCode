#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int min = INT_MAX, lmin = INT_MAX-1; 
        for (int i = 0; i < nums[i]; ++i) {
            if (nums[i] < lmin) {
                lmin = nums[i];
            }
            else if (nums[i] < min) {
                min = nums[i];
            }
            else return true;
        }
        return false;
    }
};