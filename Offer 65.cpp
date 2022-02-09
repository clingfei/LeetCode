class Solution {
public:
    int add(int a, int b) {
        int res = 0;
        while (b != 0) {
            int carry = a & b; 
            a ^= b;
            b = (unsigned)carry << 1;
        }
        return a;
    }
};