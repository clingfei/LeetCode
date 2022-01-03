#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    static bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mmap;
        for (int i = 0; i <nums.size(); ++i) {
            mmap[nums[i]]++;
        }         

        vector<pair<int, int>> tmp;
        for (auto iter = mmap.begin(); iter != mmap.end(); ++iter) {
            tmp.push_back(*iter);
        }
        sort(tmp.begin(), tmp.end(), cmp);

        vector<int>res;
        for (int i = 0; i < k; ++i)
            res.push_back(tmp[i].first);
        return res;
    }
};

