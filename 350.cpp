#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int hashTable[1001] = {0};
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            hashTable[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (--hashTable[nums2[i]] >= 0)
                res.emplace_back(nums2[i]);
        }
        return res;
    }
};