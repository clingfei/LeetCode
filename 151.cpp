#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (s[i] == ' ') i++;
        string res;
        int j = i;
        while (j < s.size() && s[j] != ' ') j++;              //截取第一个单词
        res = s.substr(i, j - i) + res;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') j++;            //跳过中间的空格
            if (j == s.size()) break;
            res = " " + res;   
            i = j;
            while (j < s.size() && s[j] != ' ') j++;          //截取中间的单词
            res = s.substr(i, j - i) + res;
        }
        return res;
    }
};