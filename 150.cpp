#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for(int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int r = sta.top();
                sta.pop();
                int l = sta.top();
                sta.pop();
                sta.push(l + r);
            }
            else if (tokens[i] == "-") {
                int r = sta.top();
                sta.pop();
                int l = sta.top();
                sta.pop();
                sta.push(l - r);
            }
            else if (tokens[i] == "*") {
                int r = sta.top();
                sta.pop();
                int l = sta.top();
                sta.pop();
                sta.push(l * r);
            }
            else if (tokens[i] == "/") {
                int r = sta.top();
                sta.pop();
                int l = sta.top();
                sta.pop();
                sta.push(l / r);
            }
            else {
                sta.push(stoi(tokens[i]));
            }
        }
        return sta.top();
    }
};