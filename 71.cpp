#include <string>

using namespace std;
 
class Solution {
public:
    string simplifyPath(string path) {
        string tmp;
        string res;
        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                if (tmp.size() == 0 &&res.size() == 0) {
                    res.push_back('/');
                    tmp.clear();
                }
                else if (tmp.size() == 0) {
                    ++i;
                    continue;
                }
                else if (tmp == ".") {
                    tmp.clear();
                }
                else if (tmp == "..") {
                    int j = res.size() - 2;
                    while (j >= 0 && res[j] != '/') 
                        --j;
                    if (j >= 0) res = res.substr(0, j + 1);
                    tmp.clear();
                }
                else {
                    res += tmp + '/'; 
                    tmp.clear();
                }
            }
            else {
                tmp.push_back(path[i]);
            }
            i++;
        }
        if (path[i - 1] != '/') {
            if (tmp == "..") {
                int j = res.size() - 2;
                while (j >= 0 && res[j] != '/') 
                    --j;
                if (j >= 0) res = res.substr(0, j + 1);
            }
            else if (tmp != ".") {
                res += tmp;
            }
        }
        if (res.size() > 1 && res[res.size() - 1] =='/')
            return res.substr(0, res.size() - 1);
        else 
            return res;
    }
};