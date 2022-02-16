#include <string>

using namespace std;


class Solution {
public:
    int strToInt(string str) {
        long res = 0;
        int i = 0;
        bool flag = false, flag1 = false, flag2= false;
        while (i < str.size()) {
            if (!isdigit(str[i]) && flag2) return res;
            if (str[i] == ' ') {
                ++i;
            } else if (str[i] == '-' ){
                flag = true;
                if (flag1) return res;
                flag1 = true;
                ++i;
            } else if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-') {
                return res;
            } else if (str[i] == '+') {
                if (flag1) return res;
                flag1= true;
                ++i;
            } else {
                flag2 = true;
                if (res == 0 && flag) {
                    res = -(str[i] - '0');
                } else if (res > 0 && res * 10 + str[i] - '0' > INT_MAX) {
                    return INT_MAX;
                } else if (res < 0 && res * 10 - (str[i] - '0') < INT_MIN) {
                    return INT_MIN;
                } else if (res >= 0) {
                    res = res * 10 + str[i] - '0';
                } else  {
                    res = res * 10 - (str[i] - '0');
                }
                ++i;
            }
        }
        return res;
    }
};