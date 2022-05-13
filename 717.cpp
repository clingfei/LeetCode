#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i ++ ) {
            if (a[i] == 1) a[i] = a[i + 1] = 2, i += 1;
        }
        return a[n - 1] == 0;
    }
};