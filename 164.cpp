#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        int max = 0;
        for (int i = 1; i < nums.size(); ++i) {
            max = max < nums[i] - nums[i-1] ? nums[i] - nums[i-1] : max;
        }
        return max;
    }
    int divide(vector<int> &nums, int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (high > low && nums[high] >= pivot) --high;
            if (high > low) {
                int temp = nums[low];
                nums[low] = nums[high];
                nums[high] = temp;
            }
            while (high > low && nums[low] <= pivot) ++low;
            if (high > low) {
                int temp = nums[low];
                nums[low] = nums[high];
                nums[high] = temp;
            }
        }
        nums[low] = pivot;
        return low;
    }
    void sort(vector<int> &nums, int low, int high) {
        if (low >= high) return;
        int mid = divide(nums, low, high);
        sort(nums, low, mid - 1);
        sort(nums, mid + 1, high);
    }
};