#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for (int i = 1; i <= wordDict.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);
                if (set.find(word) != set.end() && dp[j])
                    dp[i] = true; 
            }
        }
        return dp[s.size()];        
    }
};