#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        vector<int> alpha(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            alpha[s1[i] - 'a']++;
        }
        for (int i = 0; i < s1.size(); ++i) {
            alpha[s2[i] - 'a']--;
        }
        if (check(alpha)) return true;
        for (int i = 1; i + s1.size() <= s2.size(); ++i) {
            alpha[s2[i-1] - 'a']++;
            alpha[s2[i + s1.size() - 1] - 'a']--;
            if (check(alpha)) return true;
        }
        return false;
    }
    bool check(vector<int> &alpha) {
        for (int i = 0; i < alpha.size(); ++i) {
            if (alpha[i] > 0)
                return false;
        }
        return true;
    }
};