#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int index = 0;
        for (int i = s.size()-1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                s[i-1]--;
                index = i;
            }
        }
        for (int i = index; i < s.size(); ++i) {
            s[i] = '9';
        }
        return stoi(s);
    }
};