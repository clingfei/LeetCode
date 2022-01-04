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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            int max = INT_MIN;
            for (int i = 0; i < s; ++i) {
                TreeNode *p = q.front();
                q.pop();
                if (p->val > max) max = p->val;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            res.push_back(max);
        }
        return res;
    }
};