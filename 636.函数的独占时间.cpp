/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>id2time(n,0);
        stack<int>ids;
        vector<string>pre=split(logs[0],':');
        ids.push(stoi(pre[0]));
        for(int i=1;i<logs.size();i++){
            vector<string>cur=split(logs[i],':');
            if(cur[1]=="start"){
                if(!ids.empty())id2time[ids.top()]+=stoi(cur[2])-stoi(pre[2])-1;
                ids.push(stoi(cur[0]));
            }else {
                id2time[ids.top()]+=stoi(cur[2])-stoi(pre[2])+1;
                ids.pop();
            }
            pre=cur;
        }
        return id2time;
        
    }
    vector<string>split(string&s,char flag){
        vector<string>ans;
        stringstream ss(s);
        string cur;
        while(getline(ss,cur,flag)){
            ans.push_back(cur);
        }
        return ans;
    }
};
// @lc code=end

