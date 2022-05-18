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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int i = -1, j = 1;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *last = root;
        vector<vector<int>> res;

        if (root == nullptr) return res;
        
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (last == p) {         //说明到了一层的最左边
                last = nullptr;
                vector<int> tmp;
                res.push_back(tmp);
                ++i;
            }
            if (p == nullptr) continue;
            if (p->left != nullptr) {
                if (last == nullptr) 
                    last = p->left;
                q.push(p->left);
            }
            if (p->right != nullptr) {
                if (last == nullptr)
                    last = p->right;
                q.push(p->right);
            }
            res[i].push_back(p->val);
        }
        return res;
    }
};