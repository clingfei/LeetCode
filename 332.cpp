#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool cmp(vector<string> &a, vector<string> &b) {
        if (a[0] == "JFK" && b[0] != "JFK")
            return true;
        else if (a[0] != "JFK" && b[0] == "JFK")
            return false;
        else 
            return a[1] < b[1];
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        vector<bool> used(tickets.size(), false);
        sort(tickets.begin(), tickets.end(), cmp);
        res.emplace_back("JFK");
        backtracing(res, tickets, used);
        return res;
    }
    void backtracing(vector<string> &res, vector<vector<string>> &tickets, vector<bool> &used) {
        for (int i = 0; i < tickets.size(); ++i) {
            if (used[i] == true) continue;
            if (res.back() == tickets[i][0]) {
                res.emplace_back(tickets[i][1]);
                used[i] = true;
                if (res.size() > tickets.size()) {
                    return;
                } 
                backtracing(res, tickets, used);
                if (res.size()> tickets.size())
                    return;
                used[i] = false;
                res.pop_back();
            }
        }
    }
};