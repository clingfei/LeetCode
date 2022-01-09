#include <vector>
#include <string>

using namespace std;

class Solution {
private:
vector<string> t = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv", 
    "wxyz"
};
    void backtracing(vector<string> &res, string &temp, string digits, int index) {
        for (int i = 0; i < t[digits[index] -'0' - 2].size(); ++i) {
            temp.push_back(t[digits[index] -'0' - 2][i]);
            if (index == digits.size()-1)
                res.emplace_back(temp);
            else 
                backtracing(res, temp, digits, index+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp;
        if (digits.size() != 0)
            backtracing(res, temp, digits, 0);
        return res;
    }
};