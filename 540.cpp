#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if ((mid + 1 - low) % 2 == 0) {
                    low = mid + 1; 
                } else {
                    high = mid - 2;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                if ((mid + 1 - low) % 2 == 0) {
                    high = mid - 1;
                } else {
                    low = mid + 2;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[low];
    }
};