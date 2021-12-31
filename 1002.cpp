#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int hashTable[26] = {0};
        
        for (int j = 0; j < words[0].size(); ++j)
            hashTable[words[0][j] - 'a']++;
        for (int i = 1; i < words.size(); ++i) {
            int temp[26] = {0};
            for (int j = 0; j < words[i].size(); ++j)
                temp[words[i][j] - 'a']++;
            for (int k = 0; k < 26; k++) 
                hashTable[k] = hashTable[k] < temp[k] ? hashTable[k] : temp[k];
        }
        
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            if (hashTable[i] != 0) {
                int j = 0;
                while (j++ < hashTable[i])
                    res.emplace_back(string(1, char('a' + i)));
            }
        }
        return res;
    }
};