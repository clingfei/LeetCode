class Solution {
public:
    int totalMoney(int n) {
        int res = (n / 7) * 28 + (n/7)*(n/7-1)/2 * 7;
        res += (1+ n / 7)*(n%7) + (n%7)*(n%7-1)/2*1;
        return res;
    }
};