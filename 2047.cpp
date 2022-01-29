#include <string>

using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        int i = 0, j = 1;
        int res = 0;
        int cnt = 0;
        bool flag = false;
        while (j < sentence.size()) {
            if (sentence[j] == '-') {
                if (j - i <= 1 || j == sentence.size()-1 || sentence[j + 1] == ' ') {
                    while (i < sentence.size() && sentence[i] != ' ')
                        ++i;
                    j = i + 1;
                    cnt = 0;
                    flag = false;
                }
                else if (cnt != 0) {
                    while (i < sentence.size() && sentence[i] != ' ')
                        ++i;
                    j = i + 1;
                    cnt = 0;
                    flag = false;
                }
                else 
                    cnt = 1;
            }
            else if (isdigit(sentence[j])) {
                while(i < sentence.size() && sentence[i] != ' ') 
                    ++i;
                j = i + 1;
                flag = false;
            }
            else if (sentence[j] == ' ') {
                if (flag) res++;
                cnt = 0;
                res++;
                ++j;
                flag = false;
            }
            else if (isalpha(sentence[j])) {
                flag = true;
                ++j;
            } 
            else {
                ++j;
            }
        }
        return res;
    }
};