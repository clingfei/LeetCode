#include <string>

using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int res = 0;
        int i = 0;
        int cur = 0;
        while (i < s.size()) {
            if (s[i] == 'O') 
                ++i;
            else {
                i += 3;
                res++;
            }
        }
        return res;
    }
};