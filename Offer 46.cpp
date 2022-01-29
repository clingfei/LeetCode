class Solution {
public:
    int translateNum(int num) {
        if (num <= 9 ) return 1;
        if (num % 100 >= 26 || num % 100 <= 9) {
            return translateNum(num / 10);
        }
        else return translateNum(num / 10) + translateNum(num / 100);
    }
};