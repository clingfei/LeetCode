#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int i = 0, j = nums.size() - 1;
        if (nums[i] < 0 && nums[j] > 0) {
            while (i < j) {
                if (nums[i] < 0 && nums[i+1] >= 0)
                    break;
                i++;
            }
            j = i + 1;
            while (i >= 0 && j < nums.size()) {
                if (-nums[i] > nums[j]) 
                    result.emplace_back(nums[j] * nums[j++]);
                else 
                    result.emplace_back(nums[i] * nums[i--]);
            }
            while ( i >= 0) {
                result.emplace_back(nums[i] * nums[i--]);
            }
            while (j < nums.size()) 
                result.emplace_back(nums[j] * nums[j++]);
        }
        else if (nums[i] >= 0)
            while (i < nums.size())
                result.emplace_back(nums[i] * nums[i++]);
        else 
            while (j >= 0) 
                result.emplace_back(nums[j] * nums[j--]);
        return result;
    }
};