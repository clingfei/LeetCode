#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n == 0) return 0;
        if(n < 10) return 1;
        long long cur = 1;
        int i = 0, res = 0;
        while(cur < n) {cur *= 10; ++i;}
        cur /= 10;
        if(cur*10 == n) return i*cur+1;
        --i;
        while(cur > 0) {
            int t = n / cur;
            n = n % cur;
            if(t == 1) res += i*cur/10 + n + 1;
            else res += t * i*cur/10 + cur;
            while(cur > n) {cur /= 10; --i;} 
        }
        return res;
    }
};