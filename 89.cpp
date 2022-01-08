#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int i = 0;
        vector<int> res;
        while (i < 1<<n) {
            res.push_back(i ^ (i>>1));
            i++;
        }
        return res;
    }
};