#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(string &a, string &b) {
        return a + b < b + a;
    }
public:
    string minNumber(vector<int>& nums) {
        vector<string> temp;
        for (int i = 0; i < nums.size(); ++i) {
            temp.emplace_back(to_string(nums[i]));
        }
        sort(temp.begin(), temp.end(), cmp);
        string res;
        for (auto s : temp)
            res += s;
        return res;
    }
};