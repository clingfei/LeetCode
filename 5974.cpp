#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int seat = 0;
        for (int i = 0; i < corridor.size(); ++i) {
            if (corridor[i] == 'S')
                seat++;
        }        
        if (seat % 2 != 0 || seat == 0) return 0;
        int cnt = 0;
        int  i = 0;
        vector<double> temp;
        while (i < corridor.size()) {
            if (cnt >= 2 && cnt % 2 == 0 && cnt + 2 <= seat) {
                double c = 0;
                int a = 0;
                while (i < corridor.size() && corridor[i] == 'P') {
                    a = 1;
                    c++;
                    i++;
                }
                if (a == 1 && i != corridor.size() && i != 0)
                    c++;
                if (c != 0)
                    temp.push_back(c);
            }
            if (corridor[i] == 'S') 
                cnt++;            
            ++i;
        }
        long long res = 1;
        for (int i = 0; i < temp.size(); ++i) {
            res *= temp[i];
            res = res % int(1e9+7);
        }
        return res;
    }
};