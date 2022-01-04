#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode *> q;
        TreeNode *last = root;
        q.push(root);
        int i = -1;
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p == last) {
                i++;
                vector<int> tmp;
                res.push_back(tmp);
                last = nullptr;
            }
            res[i].push_back(p->val);
            if (p->left) {
                if (last == nullptr) 
                    last = p->left;
                q.push(p->left);
            }
            if (p->right) {
                if (last == nullptr) 
                    last = p->right;
                q.push(p->right);
            }
        }
        vector<vector<int>> ans;
        while (i >= 0) 
            ans.push_back(res[i--]);
        return res;
    }
};