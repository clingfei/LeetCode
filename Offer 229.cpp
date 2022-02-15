#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 0, count_x = 0, count_y = 0;
        for (auto num : nums) {
            if (num != y && (count_x == 0 || x == num)) {
                x = num;
                count_x++;
            } else if (count_y == 0 || y == num) {
                y = num;
                count_y++;
            } else {
                count_x--;
                count_y--;
            }
        }
        if (count_x == 0 && count_y == 0) return vector<int>{};
        int cnt_1 = 0, cnt_2 = 0;
        for (auto num:nums) {
            if (num == x) cnt_1++;
            else if (num == y) cnt_2++;
        }
        vector<int> res;
        if (cnt_1 > nums.size() / 3)
            res.emplace_back(x);
        if (cnt_2 > nums.size() / 3) 
            res.emplace_back(y);
        return res;
    }
};