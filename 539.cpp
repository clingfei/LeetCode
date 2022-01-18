#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end()); 
        int min = INT_MAX;
        int last = stoi(timePoints[0].substr(0, 2)) *60 + stoi(timePoints[0].substr(3, 2));
        int t0 = last;
        for (int i = 1; i < timePoints.size(); ++i) {
            int temp = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(0,2));       
            if (temp - last < min)
                min = temp - last;
            last = temp;
        }
        if (24 * 60 - last + t0 > min)
            return min;
        else return 24 * 60 - last + t0;


    }
};