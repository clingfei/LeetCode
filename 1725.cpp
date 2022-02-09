#include <vector>

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max = 0, res = 0;
        for (int i = 0; i < rectangles.size(); ++i) {
            if (rectangles[i][0] > max && rectangles[i][1] > max) {
                max = min(rectangles[i][0], rectangles[i][1]);
            }
        }
        for (int i = 0; i < rectangles.size(); ++i) {
            if (rectangles[i][0] >= max && rectangles[i][1] >= max) 
                res++;
        }
        return res;
    }
};