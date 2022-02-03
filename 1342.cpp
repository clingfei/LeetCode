class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while (num != 0) {
            if (num & 1) {
                --num;
            }
            else {
                num >>= 1;
            }
            res++;
        }
        return res;
    }
};