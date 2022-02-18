#include <stdint.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> res(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                res[i] |= 1 << (words[i][j] - 'a'); 
            }          
        }
        int max = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (!(res[i] & res[j]) && words[i].size() * words[j].size() > max) {
                    max = words[i].size() * words[j].size();
                }
            }
        }
        return max;
    }
};