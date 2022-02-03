#include <string>

using namespace std;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        double last = 0;
        for (int i = 0; i < s.size() && i < k ; ++i) {
            last = (last + (s[i] - 'a' + 1) * pow(power, i));
        }
        if (last - (last / modulo) * modulo == hashValue)
                return s.substr(0, k);
        for (int i = 1; i < s.size(); ++i) {
            last -= (s[i-1] - 'a' + 1);
            last /= power;
            if (i + k - 1 < s.size()) {
                last = (last + (s[i + k - 1] - 'a' + 1) * pow(power, k-1));
                if (last - (last / modulo) * modulo == hashValue)
                    return s.substr(i, k);
            }
        }
        return "";
    }
};