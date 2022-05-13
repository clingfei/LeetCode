#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> umap;
        for (auto ch : s) 
            umap[ch]++;
        int cnt = 0;
        for (auto u : umap)
            if (u.second & 1)
                cnt++;
        return cnt > 1;
    }
};