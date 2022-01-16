#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        if (s.size() % k != 0) {
            while (s.size() % k != 0) 
                s += fill;
        }
        for (int i = 0; i+k <= s.size(); i+=k) {
            res.emplace_back(s.substr(i, k));
        }
        return res;
    }
};