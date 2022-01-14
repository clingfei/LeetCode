#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>&a ,vector<int> &b) {
        return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int last = points[0][1];
        int res = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= last) {
                if (points[i][1] < last)
                    last = points[i][1];
            }
            else {
                res++;
                last = points[i][1];
            }
        }
        return res;
    }
};