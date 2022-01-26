#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

class DetectSquares {
private:
    map<pair<int, int>, int>cnt;
    unordered_map<int, unordered_set<int>> s;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        s[point[0]].insert(point[1]);
        cnt[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        for (auto iter = s[x].begin(); iter!= s[x].end(); ++iter ) {
            if (*iter != y) {           //固定了一条边，再找另一条边
                int dist = abs(*iter-y);
                if (cnt[{x-dist, y}] != 0 && cnt[{x-dist, (*iter)}] != 0) {
                    res += cnt[{x-dist, y}] * cnt[{x-dist, *iter}] * cnt[{x, *iter}];
                }
                if (cnt[{x+dist, y}] != 0 && cnt[{x+dist, (*iter)}] != 0) {
                    res += cnt[{x+dist, y}] * cnt[{x+dist, *iter}] * cnt[{x, *iter}];
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */