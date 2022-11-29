/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (umap.find(groupSizes[i]) != umap.end()) {
                umap[groupSizes[i]].push_back(i);
            } else {
                umap[groupSizes[i]] = vector<int>();
                umap[groupSizes[i]].push_back(i);
            }
        }
        for (auto &v : umap) {
            //std::cout << v.second.size() << " " << v.first << std::endl;
            for (int i = 0; i < v.second.size() / v.first; i++) {
                vector<int> tmp;
                for (int j = i * v.first; j < v.first * (i + 1); j++) {
                    tmp.emplace_back(v.second[j]);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};
// @lc code=end

