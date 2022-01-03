#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else {
                switch(s[i]) {
                    case ')': if (sta.top() != '(') return false; sta.pop(); break;
                    case ']': if (sta.top() != '[') return false; sta.pop(); break;
                    default: if (sta.top() != '{') return false; sta.pop();
                }
            }
        }
        return sta.empty();
    }
};