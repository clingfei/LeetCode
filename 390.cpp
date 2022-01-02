#include <vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int d = 2;
        int step = 0;
        int start = 1;
        while (n != 1) {
            if (step % 2 == 0 || n % 2 != 0) {   //从左到右
                start = start + d / 2;
            }
            step++;
            d *= 2;
            n /= 2;
        }
        return start;
    }
};