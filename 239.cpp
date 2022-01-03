#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    deque<int> q;

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] > q.front())
                q.pop_back();
            q.push_back(nums[i]);    
        }
        res.push_back(q.front());
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i - k] == q.front()) q.pop_front(); 
            while (!q.empty() && nums[i] > q.front())
                q.pop_back();   
            q.push_back(nums[i]);
            res.push_back(q.front());
        }
        return res;
    }
};





