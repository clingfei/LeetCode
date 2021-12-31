#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mmap;
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); ++iter) {
            string tmp = *iter;
            sort(tmp.begin(), tmp.end());
            mmap[tmp].emplace_back(*iter);
        }
        vector<vector<string>> res;
        for (unordered_map<string, vector<string>>::iterator iter = mmap.begin(); iter != mmap.end(); ++iter) {
            res.emplace_back(iter->second);
        }
        return res;
    }  
};