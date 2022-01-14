#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         vector<vector<int>> v;
         int n = nums1.size(), m = nums2.size();
         auto cmp = [&](const pair<int, int>&lhs, const pair<int, int>& rhs) {
             return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
         };
         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>heap(cmp);
         for (int i = 0; i < nums1.size(); ++i) {
              heap.push({i, 0});
         }

         vector<vector<int>> ret;
         while (k-- > 0 &&!heap.empty()) {
             auto ids = heap.top();
             heap.pop();
             ret.push_back({nums1[ids.first], nums2[ids.second]});
             if (ids.second < nums2.size()-1) {
                 heap.push({ids.first, ids.second + 1});
             }
         }
         return ret;
    }
};