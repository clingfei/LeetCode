#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0, end = k;
        while (end <= s.size()) {
            reverse(s, start, start+k-1);
            start += 2 * k;
            end += 2 * k;
        }
        if (end > s.size())     //
            reverse(s, start, s.size()-1);
        return s;
    }
    void reverse(string &s, int start, int end) {
        while (start < end) {
            int temp = s[start];
            s[start++] = s[end];
            s[end--] = temp;
        }
    }
};