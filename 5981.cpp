#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> zero(nums.size() + 1, 0);
        for (int i = 1; i < nums.size()+1; ++i) {
            if (nums[i - 1] == 0) 
                zero[i] += zero[i-1] + 1;
            else {
                zero[i] = zero[i-1];
            }
        }
        vector<int> one(nums.size()+1, 0);
        unordered_map<int, int> umap;

        if (nums.back() == 1) one.back() = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == 1) {
                one[i] = one[i+1] + 1;
            }
            else {
                one[i] = one[i+1];
            }
        }
        int max = 0;
        for (int i = 0; i < nums.size()+1; ++i) {
            if (one[i] + zero[i] > max) 
                max = one[i] + zero[i];
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size()+1; ++i) {
            if (one[i] + zero[i] == max) 
                res.emplace_back(i);
        }
        return res;
    }
};