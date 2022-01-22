#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> que;
        vector<int> isVisited(arr.size(), 0);
        que.push(start);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            if (arr[p] == 0) 
                return true;
            isVisited[p] = 1;
            
            if (p - arr[p] >= 0 && p - arr[p] < arr.size()) {
                if (isVisited[p-arr[p]] == 0)
                    que.push(p-arr[p]);
            }
            if (p + arr[p] >= 0 && p + arr[p] < arr.size()) {
                if (isVisited[p+arr[p]] == 0)
                    que.push(p+arr[p]);
            }
        }      
        return false;
    }
};