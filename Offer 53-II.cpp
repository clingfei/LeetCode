#include <vector>

using namespace std;

class Solution {
public:
//esclusive
    int missingNumber(vector<int>& nums) {
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            temp ^= nums[i] ^ i;
        }
        temp ^= nums.size();
        return temp;
    }
    int missingNumber(vector<int> &nums) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = (low+high) / 2;
            if (nums[mid] == mid)
                low = mid + 1;
            else 
                high = mid - 1;
        } 
        return low;
    }
};