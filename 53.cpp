#include <vector>

using namespace std;

class Solution {
public:
    int test(int a, int b) {}
    int test(int a, int b) {}
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        int i = 0;
        while (i < nums.size()) {
            sum += nums[i];
            if (sum > max) 
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};