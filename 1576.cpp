#include <string>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '?') {
                if (i == 0) {
                    if (i + 1 < s.size() && s[i+1] != '?')
                        s[i+1] == 'a' ? s[i] = 'b' : s[i] = 'a';
                    else 
                        s[i] = 'a';
                }
                else {
                    if (i + 1 == s.size() || s[i+1] == '?')
                        s[i - 1] == 'a' ? s[i] = 'b' : s[i] = 'a';
                    else {
                        if (s[i - 1] == 'a' || s[i+1] == 'a') {
                            if (s[i - 1] == 'b' || s[i + 1] == 'b')
                                s[i] = 'c';
                            else 
                                s[i] = 'b';
                        }
                        else 
                            s[i] = 'a';
                    }
                }
            }
        }
        return s;
    }
};