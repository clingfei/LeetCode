/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> pmax(arr.size());
        vector<int> pmin(arr.size());
        pmax[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            pmax[i] = pmax[i - 1] > arr[i] ? pmax[i - 1] : arr[i];
        }
        pmin[arr.size() - 1] = arr[arr.size() - 1];
        for (int i = arr.size() - 2; i >= 0; i--) {
            pmin[i] = arr[i] < pmin[i + 1] ? arr[i] : pmin[i + 1];
        }
        int res = 0;\\
                for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size() - 1 || pmax[i] <= pmin[i + 1])
                res++;
        }
        return res;
    }
};
// @lc code=end

