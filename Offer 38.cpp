#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_set<string> uset;
public:
    vector<string> permutation(string s) {
        string temp;
        vector<bool> isVisited(s.size(), 0);
        vector<string> res;
        for (int i = 0; i < s.size(); ++i) {
            temp.push_back(s[i]);
            isVisited[i] = true;
            backtracing(res, s, isVisited, temp);
            isVisited[i] = false;
            temp.pop_back();
        } 
        return res;
    }
    void backtracing(vector<string> & res, string s, vector<bool> &isVisited, string &temp) {
        if (temp.size() == s.size()) {
            if (uset.find(temp) == uset.end()) {
                res.emplace_back(temp);
                uset.insert(temp);
            }
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!isVisited[i]) {
                temp.push_back(s[i]);
                isVisited[i] = true;
                if (uset.find(temp) == uset.end()) {
                    //cout << temp;
                    backtracing(res, s, isVisited, temp);
                    uset.insert(temp);
                }
                isVisited[i] = false;
                temp.pop_back();
            }
        }
    }
};