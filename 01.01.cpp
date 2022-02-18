#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int temp = 0;
        unordered_map<char, int> umap;
        for (int i = 0; i < astr.size(); ++i) {
            if (umap[astr[i]] != 0) return false;
            umap[astr[i]]++;    
        }
        return true;
    }
};