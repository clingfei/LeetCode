#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    static int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (gcd(i, j) == 1) {
                    res.emplace_back(to_string(i) + "/" + to_string(j));;
                }
            }
        }
        return res;
    }
};