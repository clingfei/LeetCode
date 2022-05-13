#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long cnt = 0;
        unordered_map<int, int> umap;
        int n = nums1.size();  
        for (int i = 0; i < n; ++i) 
            umap[nums2[i]] = i;
        for (int i = 0; i < n; ++i) {
            int p1 = umap[nums1[i]];
            for (int j = i + 1; j < n; ++j) {
                int p2 = umap[nums1[j]];
                if (p2 > p1) {
                    for (int k = j + 1; k < n; ++k) {
                        int p3 = umap[nums1[k]];
                        if (p3 > p2 && p3 > p1)
                            cnt++;
                    }
                 }
            }
        }
        return cnt;
    }
};