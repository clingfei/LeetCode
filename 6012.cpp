#include <vector>

using namespace std;

static vector<int> dp(1001);
class Solution {
public:
    int countEven(int num) {
        int sum = 0;
        int t = num;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum % 2 == 0)
            return t / 2;
        else return t / 2 - 1;
    }
};