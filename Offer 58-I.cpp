#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = 0, j = 0;
        while (i < s.size()) {
            while (s[i] == ' ') 
                ++i;
            j = i;
            while (j < s.size() && s[j] != ' ')
                ++j;
            if (j - i == 0) 
                break;
            if (res.size() != 0) {
                res = s.substr(i, j-i) + " " + res;
            }
            else res += s.substr(i, j - i);
            i = j;
        }
        return res;
    }
};