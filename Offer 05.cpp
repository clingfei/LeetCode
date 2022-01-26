#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (char i : s) {
            if (i == ' ') 
                s += "%20";
            else 
                s.push_back(i);
        }
        return res;
    }
};