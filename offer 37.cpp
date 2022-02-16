#include <ctype.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *p = que.front();
            que.pop();
            if (p != nullptr) {
                res += to_string(p->val) + ",";
            } else {
                res += "null,";
            }
            if (p != nullptr) {
                que.push(p->left);
                que.push(p->right);
            }
        }
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //for (int i = 0; i < data.size(); ++i) cout << data[i];
        if (data.size() == 0) return nullptr;
        vector<TreeNode*> vec;
        for (int i = 0; i < data.size(); ++i) {
            int j = i;
            while (j < data.size() && data[j] != ',')
                ++j;
            string temp = data.substr(i,j-i);
            if (temp == "null") vec.emplace_back(nullptr);
            else vec.emplace_back(new TreeNode(stoi(temp)));
            i = j;
        }
        for (int i = 0, cnt = 0; i < vec.size(); ++i) {
            if (vec[i] == nullptr) continue;
            if (2 * cnt + 1 < vec.size()) vec[i]->left = vec[2 * cnt + 1];
            if (2 * cnt + 2 < vec.size()) vec[i]->right = vec[2 * cnt + 2];
            ++cnt;
        }
        return vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));