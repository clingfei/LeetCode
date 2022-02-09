#include <functional>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.push(arr[i]);
        }
        vector<int> res;
        while (k > 0) {
            res.emplace_back(pq.top());
            pq.pop();
            k--;
        }
        return res;
    }
};