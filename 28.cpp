#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        vector<int> next(needle.size());
        next[0] = -1;
        int i = 0, j = -1;
        while (i < needle.size()-1) {
            if (j == -1 || needle[i] == needle[j]) {
                ++i; ++j;
                if (needle[i] != needle[j]) next[i] = j;
                else next[i] = next[j];
            }
            else 
                j = next[j];
        }
        i=0, j = 0;
        while (i < int(haystack.length()) && j < int(needle.length())) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i; ++j;
            }
            else {
                j = next[j];
            }
        }
        return j == needle.size() ? i - needle.size() : -1;
    }
};