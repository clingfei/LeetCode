/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k != 1) { 
            sort(s.begin(), s.end());
            return s;
        }
        string min = s;
        s = min + s;
        for (int i = 0; i < min.size(); ++i) {
            if (s.substr(i, min.size()) < min) {
                min = s.substr(i, min.size());
            }
        }    
        return min;
    }
};
// @lc code=end

