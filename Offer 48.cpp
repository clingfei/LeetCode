#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int max = 0, cur = -1;
        
        for (int i = 0; i < s.size(); ++i) {
            if (umap.find(s[i]) != umap.end()) {
                if (umap[s[i]] > cur)
                    cur = umap[s[i]];
            }
            umap[s[i]] = i;
            if (i - cur > max) 
                max = i - cur;
        }
        return max;
    }
};