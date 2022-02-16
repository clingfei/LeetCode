#include <vector>
#include <queue>

using namespace std;

class Solution {
    struct cmp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        }
    };
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        vector<int> res;
        if (nums.size() == 0) return res;  
        for (int i = 0; i < k; ++i)
            que.push({nums[i], i});
        res.emplace_back(que.top().first);
        for (int i = 1; i + k <= nums.size(); ++i) {
            //cout << i;
            while (!que.empty() &&que.top().second < i) {
                que.pop();
            }
            que.push({nums[i + k - 1], i + k - 1});
            res.push_back(que.top().first);
        }
        return res;
    }
};