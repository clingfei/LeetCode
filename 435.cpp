#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
       
        int res = 0;
        int last = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < last) {
                res++;  
                if (intervals[i][1] < last)
                    last = intervals[i][1];                 //需要更新Last为迄今为止最短的区间，只有重合的部分最短，才能找到最少的删除次数。
            }
            else 
                last = intervals[i][1];
        }       
        return res;
    }
};