/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        for (auto && p1 : points) {
            for (auto && p2 : points) {
                for (auto && p3 : points) {
                    double x1 = p1[0];
                    double x2 = p2[0] - x1;
                    double x3 = p3[0] - x1;
                    double y1 = p1[1];
                    double y2 = p2[1] - y1;
                    double y3 = p3[1] - y1;
                    double tmp = abs(x2 * y3 - x3 * y2) / 2;
                    if (tmp > res)
                        res = tmp;
                }
            }
        }
        return res;
    }
};
// @lc code=end

