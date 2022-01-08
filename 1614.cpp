#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        stack<char> sta;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sta.push('(');
                if (sta.size() > max)
                    max = sta.size();
            }
            else if (s[i] == ')')
                sta.pop();
        }
        return max;
    }
};