#include <functional>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> que;
    int _k;
    int cur = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        if (nums.size() == 0) return;
        sort(nums.begin(), nums.end());
        if (nums.size() > k) {
            cur = nums[nums.size() - k];
            for (int i = nums.size()-1; i >= nums.size() - k; --i) {
                que.push(nums[i]);
            }
        } else {
            cur = nums.front();
            for (int i = 0; i < nums.size(); ++i) {
                que.push(nums[i]);
            } 
        }
    }
    
    int add(int val) {
        if (que.size() < _k) {
            que.push(val);
            cur = que.top();
            return cur;
        } 
        if (val <= cur) return cur;
        else {
            que.pop();
            que.push(val);
            cur = que.top();
            return cur;
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */