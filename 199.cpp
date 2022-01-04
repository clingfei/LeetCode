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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *>q;
        vector<int> res;
        if (root = nullptr) return res;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                TreeNode *p = q.front();
                if (p->left != nullptr) q.push(p->left);
                if (p->right != nullptr) q.push(p->right);
                if (i == s-1) res.push_back(p->val);
                q.pop();
            }
        }
        return res;
    }
};