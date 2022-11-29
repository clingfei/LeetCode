/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;
        int count = 0;
        vector<string> store;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') 
                count++; 
            else
                count--;
            // count == 0表示前半序列0的数量和1的数量相等，同时我还要判断后面的半个序列是否满足要求
            if (count == 0) {
                store.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                left = i + 1;
            }
        }
        sort(store.begin(), store.end(), greater<string>{});
        string res;
        for (auto iter = store.begin(); iter != store.end(); iter++) {
            res += *iter;
        }
        return res;
    }
};
// @lc code=end

