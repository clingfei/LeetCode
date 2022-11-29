/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class OrderedStream {
private:
    int ptr;
    vector<string> stream;
public:
    OrderedStream(int n) {
        ptr = 1;
        stream.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> res;
        if (ptr < stream.size() && stream[ptr] != "") {
            for (int i = ptr; i < stream.size(); i++) {
                if (stream[i] != "") {
                    res.push_back(stream[i]);
                    ptr++;
                } else break;
            }
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

