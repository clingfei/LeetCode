#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        double max = INT_MIN, min = INT_MAX;
        double cur = 0;
        for (int i = 0; i < differences.size(); ++i) {
            cur += differences[i];
            if (cur < min) min = cur;
            if (cur > max) max = cur;
        }
        int res = 0;
        for (double i = lower; i <= upper; ++i) {
            if (i + max <= upper && i + min >= lower ) res++;
        }
        return res;
    }
};