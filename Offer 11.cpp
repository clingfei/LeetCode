#include <vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int res = numbers.size() - 1;
        while (res >= 1 && numbers[res] >= numbers[res-1])
            res--;
        return numbers[res];
    }
};