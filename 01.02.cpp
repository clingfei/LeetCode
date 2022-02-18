#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> umap;
        for (int i = 0; i < s1.size(); ++i) {
            umap[s1[i]]++;
        }
        for (int i = 0; i < s2.size(); ++i) {
            umap[s2[i]]--;
        }
        for (auto iter = umap.begin(); iter != umap.end(); ++iter) 
            if (iter->second != 0)
                return false;
        return true;
        //return iter1 == umap1.end() && iter2 == umap2.end();
    }
};