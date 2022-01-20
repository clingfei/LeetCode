#include <vector>
#include <algorithm>

using namespace std;
  
class Solution {
private:
    struct elem {
        int val;
        int cnt;
    };
    void count(vector<elem> &array, int index, int val) {
        array[index].val = val;
        array[index].cnt = 0;
        while (val!=0) {
            array[index].cnt += val & 1;
            val >> 1;
        }
    }

    static bool cmp(elem a, elem b) {
        return a.cnt < b.cnt || a.cnt == b.cnt && a.val < b.val;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<elem> array(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            count(array, i, arr[i]); 
        }
        sort(array.begin(), array.end(), cmp);
        vector<int> res;
        for (int i = 0; i < array.size(); ++i) 
            res.emplace_back(array[i].val);
        return res;
    }
};