#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s = unordered_set<int>(nums1.size(), nums2.size());
        unordered_set<int> resset;
        for (int i = 0; i < nums2.size(); ++i) {
            if (s.find(nums2[i]) != s.end()) {
                resset.insert(nums2[i]);
            }
        }
        return vector<int>(resset.begin(), resset.end());
    }
};