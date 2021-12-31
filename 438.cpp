#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0, j = i + p.size();
        vector<int> res;
        if (s.size() < p.size()) return res;
        vector<int> pFreq(26);
        for (int i = 0; i < p.size(); ++i) 
            pFreq[p[i] - 'a']++;
        vector<int> sFreq(26);
        int cnt = p.size();
        for (int i = 0; i < s.size(); ++i) {
            if (++sFreq[s[i] - 'a'] <= pFreq[s[i] - 'a']) 
                cnt--;
            if (i >= p.size()) {
                sFreq[s[i] - 'a']--;
                if (sFreq[s[i] - 'a'] < pFreq[s[i] - 'a'])
                    cnt++;
            }
            if (cnt == 0)
                res.emplace_back(i - p.size() + 1);
        }
        return res;
    }
};
