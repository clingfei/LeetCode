#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;
        for (int i = 0; i < s.size(); ++i) {
            if (!sta.empty() && s[i] == sta.top())
                sta.pop();
            else 
                sta.push(s[i]);
        }
        string res;
        while (!sta.empty()) {
            res.push_back(sta.top());
            sta.pop();
        }
        reverse(res);
        return res;
    }
    void reverse(string &res) {
        int i = 0, j = res.size() - 1;
        while (i < j) {
            char tmp = res[i];
            res[i++] = res[j];
            res[j--] = tmp;
        }
    }
};