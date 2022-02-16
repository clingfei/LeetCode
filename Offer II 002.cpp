#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size() - 1;
        string res;
        int cnt = 0;
        while (i >= 0 && j >= 0) {
            res.push_back((a[i] - '0' ^ b[j] - '0' ^ cnt) + '0');
            cnt = (a[i] - '0' & b[j] - '0') | (a[i] - '0' & cnt) | (b[j]- '0' & cnt);
            --j;--i;
            //cout << res << endl;
        }
        //cout << res;
        while (i >= 0) {
            res.push_back(a[i]-'0' ^ cnt + '0');
            cnt &= a[i--] - '0';
        }
        while (j >= 0) {
            res.push_back(b[j] - '0' ^ cnt + '0');
            cnt &= b[j--] - '0';
        }
        if (cnt == 1) res.push_back('1');
        reverse(res.begin(), res.end());
        for (i = 0; i < res.size() -1 && res[i] == '0'; ++i);
        //return res;
        return string(res.begin() + i, res.end());
    }
};