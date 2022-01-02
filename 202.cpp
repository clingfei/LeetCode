#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = 0;
        while (true) {
            sum += (n % 10) * (n % 10);
            n /= 10;
            if (n == 0) {
                if (sum == 1) return true;
                else if (s.find(sum) != s.end()) return false;
                else {
                    s.insert(sum);
                    n = sum;
                    sum = 0;
                }
            }
        }
    }
};