#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        if (target == 1) return 0;
        if (target & 1) {
            target--;
            cnt++;
        } 
        int i = 0;
        while (i < maxDoubles) {
            if (target == 1) break;
            if (target % 2 == 1) {
                target--;
                cnt++;
            }
            else {
                target /= 2;
                cnt++;
                ++i;
            }
        }
        cnt += target - 1;
        return cnt;
    }
};