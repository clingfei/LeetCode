#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(0, s.size());
        next[0] = -1;
        int j = -1;
        for (int i = 0; i < s.size(); ++i) {
            while (j != -1 || s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;    
        }

        return next[s.size() - 1] != -1 && (s.size() % (s.size() - next[s.size() - 1] - 1)) == 0;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string res = s.substr(1, s.size()-1) + s.substr(0, s.size()-1);
        return res.find(s) != string::npos;
    }    
};


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string res = s.substr(1, s.size()-1) + s.substr(0, s.size()-1);

        vector<int> next(s.size());
        next[0] = -1;
        int i = -1, j = 0;
        while (j < s.size() - 1) {
            if (i == -1 || s[i] == s[j]) {
                i++; j++;
                if (s[i] == s[j]) next[j] = next[i];
                else next[j] = i;
            }
            else i = next[i];
        }
        i = 0, j = 0;
        while (i < int(s.size()) && j < int(res.size())){
            if (i == -1 || s[i] == res[j]) {
                ++i;++j;
            }
            else i = next[i];
        }
        return i == s.size();
    }    
};