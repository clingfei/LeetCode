#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> &b) {
        return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                if (intervals[i][1] >= end)
                    end = intervals[i][1];
            }
            else {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }       
        res.push_back({start, end}); 
        return res;
    }
};