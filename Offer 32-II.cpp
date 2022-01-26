#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> temp;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *p = que.front();
                que.pop();
                temp.emplace_back(p->val);
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};