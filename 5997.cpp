#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        int a  = num / 3;
        if (a * 3 == num) {
            res.emplace_back(a - 1);
            res.emplace_back(a);
            res.emplace_back(a + 1);
        }
        return res;
    }
};