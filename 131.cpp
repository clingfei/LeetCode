#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        for (int i = 0; i < s.size(); ++i) {
            if (!check(s, 0, i)) continue;
            temp.emplace_back(s.substr(0, i + 1));
            if (i == s.size() - 1)  
                res.emplace_back(temp);
            else 
                backtracing(res, temp, s, i + 1);
            temp.pop_back();
        }
        return res;
    }
    bool check(string s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void backtracing(vector<vector<string>>&res, vector<string> &temp, string s, int start) {
        for (int i = start; i < s.size(); ++i) {
            if (!check(s, start, i)) 
                continue;
            temp.emplace_back(s.substr(start, i - start + 1));
            if (i == s.size() - 1)  res.emplace_back(temp);
            else 
                backtracing(res, temp, s, i + 1);
            temp.pop_back();
        }

    }

};