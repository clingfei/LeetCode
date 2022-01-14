#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (i = 0; i < nums.size(); ++i) {
            if (k == 0) break;
            if (nums[i]<0) {
                nums[i] = -nums[i];
                k--;
            }
            else if (nums[i] == 0) {
                k = 0;
                break;
            }
            else 
                break;
        }
        int sum = 0;
        if (k % 2 == 0) {
            for (int i = 0; i < nums.size(); ++i)
                sum += nums[i];
        }
        else {
            if (i == 0) {
                sum += -nums[0];
                for (i = 1; i < nums.size(); ++i)
                    sum += nums[i];
            }
            else if (i == nums.size()) {
                sum += -nums[nums.size()-1];
                for (i = 0; i < nums.size()-1;++i) 
                    sum += nums[i];
            }
            else {
                if (nums[i] > nums[i-1]) {
                    sum += -nums[i-1];
                    int j;
                    for (j = 0; j < i-1; ++j) 
                        sum += nums[j];
                    for (j = i; j<nums.size(); ++j)
                        sum += nums[j];
                }
                else {
                    sum += -nums[i];
                    int j;
                    for (j = 0; j < i; ++j) 
                        sum += nums[j];
                    for (j = i+1; j<nums.size(); ++j)
                        sum += nums[j];
                }
            }
        }
        return sum;
    }
};