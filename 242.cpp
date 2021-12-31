#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mmap;
        for (int i = 0; i < s.size(); ++i) {
            mmap[s[i]]++;
        }
        for (int i = 0; i < t.size(); ++i) {
            if (mmap.find(t[i]) == mmap.end()) return false;
            if (--mmap[t[i]] < 0) return false;
        }
        for (unordered_map<char, int>::iterator iter = mmap.begin(); iter != mmap.end(); ++iter) {
            if (iter->second > 0)   return false;
        }
        return true;
    }
};