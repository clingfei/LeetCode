#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int max = 0;
        int res = 0;
        for (int i = 0; i < properties.size(); ++i) {
            if (properties[i][1] < max) 
                res++;
            else if (properties[i][1] > max)
                max = properties[i][1];
        }
        return res;
    }
};