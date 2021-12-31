#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0;
        int total = 0;
        int cur = 0;
        unordered_map<int, int> mmap;
        while (i < fruits.size()) {
            if (mmap.size() < 2) {
                mmap[fruits[i++]]++; 
                cur++;
            }
            else if (mmap.find(fruits[i]) != mmap.end()) {
                mmap[fruits[i++]]++; 
                cur++;
            }
            else {
                if (cur > total) total = cur;
                mmap[fruits[j]]--;
                cur--;
                if (mmap[fruits[j]] == 0) mmap.erase(mmap.find(fruits[j]));
                j++;
            }
        }
        return total > cur ? total : cur;
    }
};