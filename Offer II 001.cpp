#define INT_MAX 0x7fffffff
#define INT_MIN 0xffffffff
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) return INT_MAX;
        if (b == 1) return a;
        if (b == -1) return -a;
        int sign = a > 0 ^ b > 0;
        int res = 0;
        long a1 = abs(a);
        long b1 = abs(b);
        while (a1 >= b1) {
            long value = b1;
            int cnt = 1;
            while (a >= value) {
                a -= value;
                res += cnt;
                value <<= 2;
                cnt <<= 2;
            }
        }
        return sign == 0 ? res : -res;
    }
};