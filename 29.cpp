#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        int sign = dividend > 0 ^ divisor > 0;
        long a = dividend, b = divisor;
        a = abs(a);
        b = abs(b);
        int res = 0;
        while (a >= b) {
            long value = b;
            int cnt = 1;
            while (a >= value) {
                a -= value;
                res += cnt;
                value <<= 1;
                cnt <<=1;
            }
        }
        return sign == 0 ? res : -res;   
    }
};