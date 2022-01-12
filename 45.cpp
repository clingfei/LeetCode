#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int cover = nums[0];
        int res = 0;
        int nextDistance = 0;
        int curDistance = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            nextDistance = max(i + nums[i], nextDistance);
            if (i == curDistance) {
                res++;
                curDistance = nextDistance;
                nextDistance = 0;
            }
        }
        return res;
    }
};