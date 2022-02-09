#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt ^= nums[i];
        }
        int flag = (-cnt) & cnt;
        vector<int> res;
        int cnt1 = cnt;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & flag) {
                cnt ^= nums[i];
            } else {
                cnt1 ^= nums[i];
            }
        }
        res.emplace_back(cnt);
        res.emplace_back(cnt1);
        return res;
    }
};