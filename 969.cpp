#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int i = 0, j = 0;
        while (j < arr.size()) {
            auto iter = max_element(arr.begin(), arr.end() - j);
            if (iter + j == arr.end()) {
                ++j;
                continue;
            }
            if(iter != arr.begin()) {
                reverse(arr.begin(), iter + 1);
                res.emplace_back(iter - arr.begin() + 1);
            }
            res.emplace_back(arr.size() - j);
            reverse(arr.begin(), arr.end() - j);
            ++j;
        }
        return res;
    }
};