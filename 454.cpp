#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> ma;
        unordered_map<int, int> md;
        for (int a : nums1) {
            for (int b : nums2) {
                ma[a + b]++;
            }
        }
        int cnt = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                if (ma.find(-(c + d)) != ma.end())
                    cnt += ma.find(-(c + d))->second;
            }
        }
        return cnt;
    }
};