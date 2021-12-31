#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mmap;
        for (string::iterator iter = magazine.begin(); iter != magazine.end(); ++iter) {
            mmap[*iter]++;
        }
        for (string::iterator iter = ransomNote.begin(); iter != ransomNote.end(); ++iter) {
            if (mmap.find(*iter) == mmap.end()) return false;
            if (--mmap[*iter] < 0) return false;
        }
        return true;
    }
};