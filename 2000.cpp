#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        while (i < word.size() && word[i] != ch) {
            ++i;
        }
        if (i == word.size()) return word;
        int j = 0, k = i;
        while (j < k) {
            char temp = word[j];
            word[j] = word[k];
            word[k] = temp;
        }
        return word;
    }
};