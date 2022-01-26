#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int i = 0;
        unordered_map<char, int>  hash;
        queue<int> que;
        while (i < s.size()) {
            hash[s[i]]++;
            if (hash[s[i]] == 1) {
                que.push(i);
            }
            else {
                while (!que.empty() && hash[s[que.front()]] > 1)
                    que.pop();
            }
            ++i;
        }
        return que.empty() ? ' ' : s[que.front()];
    }
};