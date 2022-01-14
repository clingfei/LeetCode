#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5 = 0;
        int n10 = 0;
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) n5++;
            else if (bills[i] == 10) {
                n5--;
                n10++;
            }
            else {
                n10--;
                n5--;
            }
            if (n5 < 0) return false;
            if (n5 + n10 * 2 < 0) return false;
        }        
       // cout << n5 << n10;
        if (n5 < 0) return false;
        if (n5 + n10 * 2 < 0) return false;
        return true;
    }
};