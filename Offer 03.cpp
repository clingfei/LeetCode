#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> uset;
        for (auto &i: nums) {
            if (uset.find(i) != uset.end())
                return i;
            uset.insert(i);
        }
        return -1;
    }
};