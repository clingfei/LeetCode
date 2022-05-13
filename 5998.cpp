#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum & 1 || finalSum == 0)
            return res;
        long long cnt = 2;
        long long sum = 2;
        res.emplace_back(2);   
        while (sum < finalSum) {
            cnt += 2;
            sum += cnt;
            res.emplace_back(cnt);
        }
        if (sum == finalSum) {
            return res;
        } else {
            int i = res.size() - 1;
            while (i >= 0) {
                if (sum - res[i] >= finalSum) {
                    sum -= res[i];
                    res.erase(res.begin() + i);
                } else {
                    --i;
                }
                if (sum == finalSum) return res;
            } 
        }
        return res;
    }
};