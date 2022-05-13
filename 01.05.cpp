#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int cnt = 0;
        if (abs(int(first.size()) - int(second.size())) >= 2)
            return false;
        for (int i = 0, j = 0; i < first.size() && j < second.size(); ++i, ++j) {
            if (first[i] == second[j])
                continue;
            else {
                if (first.size() == second.size())
                    cnt++;
                else if (first.size() < second.size()) {
                    if (first[i] == second[j+1]) {
                        ++j;
                    } else {
                        --i;
                    }
                    cnt++;
                }
                else if (first.size() > second.size()) {
                    if (first[i + 1] == second[j]) {
                        ++i;
                    } else {
                        --j;
                    }
                    cnt++;
                }
                if (cnt >= 2)
                    return false;
            }
        }
        return true;
    }
};