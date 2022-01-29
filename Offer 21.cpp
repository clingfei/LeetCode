#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0;
        while (low < nums.size() && (nums[low] % 2 == 1)) low++;
        int high = nums.size()-1;
        while (low < high) {
            while (low < high && (nums[high] % 2 == 0)) high--;
            if (low < high) {int temp = nums[high]; nums[high] = nums[low]; nums[low] = temp;}
            while (low < high && (nums[low] % 2 == 1)) low++;
            if (low < high) {int temp = nums[high]; nums[high] = nums[low]; nums[low] = temp;}
        }
        return nums;
    }
};