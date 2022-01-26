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
        int cur = 0;
        deque<TreeNode*> que;
        que.push_back(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            if (cur % 2 == 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode *p = que.back();
                    que.pop_back();
                    temp.emplace_back(p->val);
                    if (p->right) que.emplace_front(p->right);
                    if (p->left) que.emplace_front(p->left);
                }
            }
            else {
                for (int i = 0; i < size; ++i) {
                    TreeNode *p = que.front();
                    que.pop_front();
                    temp.emplace_back(p->val);
                    if (p->left) que.emplace_back(p->left);
                    if (p->right) que.emplace_back(p->right);
                }
            }
            cur++;
            res.push_back(temp);
        }
        return res;
    }
};