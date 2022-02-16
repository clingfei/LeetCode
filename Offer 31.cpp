#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;
        int i = 0;
        int j = 0;
        while (i < pushed.size()) {
            sta.push(pushed[i++]);
            while (!sta.empty() && sta.top() == popped[j]) {
                sta.pop();
                ++j;
            }
        }
        return sta.empty();
    }
};