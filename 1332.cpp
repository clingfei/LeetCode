#include <string>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i;
                --j;
            }
            else break;
        }
        if (i >= j) return 1;
        else return 2;
    }
};