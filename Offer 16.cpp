#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
       if (x == 0) return 0;
       double res = 1;
       long long int n1 = n;
        if (n1 < 0) {
            x = 1 / x;
            n1 = -n1; 
        }
        while (n1 != 0) {
            if (n1 & 1) {
                res *= x;
            }
            x *= x;
            n1  = n1 >> 1;
        }
        return res;
    }
};