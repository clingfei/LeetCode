#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> temp;
        while (num != 0) {
            temp.emplace_back(num % 10);
            num /= 10;
        }        
        while (temp.size() != 4) {
            temp.emplace_back(0);
        }
        sort(temp.begin(), temp.end());
        return temp[0] * 10 + temp[2] + temp[1] * 10 + temp[3];
    }
};