#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        int i = 2;
        if (num <= 1) return false;
        while (i <= sqrt(num)) {
            if (num % i == 0) {
                num / i == i? sum += i : sum = sum + i + num / i;
            }
            i++;
        }
        return num == sum;

    }
};