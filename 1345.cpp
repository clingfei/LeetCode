#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1)  return 0;
        unordered_map<int, vector<int>> index;
        for (int i = 0; i < arr.size(); ++i) {
            if (index.find(arr[i]) == index.end()) {
                vector<int> temp;
                temp.push_back(i);
                index.insert(pair<int, vector<int>>(arr[i], temp));
            }
            else 
                index[arr[i]].emplace_back(i);
        }
        int res = 0;
        queue<int> que;
        vector<bool> isVisted(arr.size(), false);
        que.push(0);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int p = que.front();
                que.pop();
                if (p == arr.size()-1)
                    return res;
                isVisted[p] = true;
                if (p+1 < arr.size()) {
                    if (isVisted[p + 1] == false)
                        que.push(p+1);
                } 
                if (p-1 >= 0)
                    if (isVisted[p-1] == false)
                        que.push(p-1);
                for (int i = 0; i < index[arr[p]].size(); ++i) { 
                    if (isVisted[index[arr[p]][i]] == false)
                        que.push(index[arr[p]][i]);
                }
                index[arr[p]].clear();
            }
            res++;
        }
        return res;
    }
};    