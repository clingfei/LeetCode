#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool is_true(int a[]) {
        for (int i = 0; i <= 'z' - 'A'; ++i)
            if (a[i] > 0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int a['z' - 'A' + 1];
        memset(a, 0, sizeof(a));
        for (const char ch : t) a[ch - 'A']++;
        int i = 0, j = 0;
        string res;
        while (j < s.size()) {
            if (--a[s[j++]-'A'] == 0 && is_true(a)) {
                while(++a[s[i++]-'A'] <= 0);
                if (res.size() == 0 || res.size() > j-i) res = s.substr(i-1, j-i+1);
            }
        }
        return res;
    }
};