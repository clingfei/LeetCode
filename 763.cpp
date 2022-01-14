#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int max = -1;
        int last = -1;
        unordered_map<char, int> mmap;
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            mmap[s[i]] = i;
        }        
        for (int i = 0; i < s.size(); ++i) {
            if (mmap[s[i]] > max)
                max = mmap[s[i]]; 
            if (max == i) {
                res.emplace_back(i - last);
                last = i;
            }
        }
        return res;
    }
};