//
// Created by fsindustry on 2022/9/5.
//

#include <string>
#include <stack>
#include <vector>

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
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) {
            return {};
        }

        if (!root->left && !root->right) {
            return {to_string(root->val)};
        }

        vector<string> res;
        if (root->left) {
            vector<string> leftRes = binaryTreePaths(root->left);
            for (string &s:leftRes) {
                res.push_back(to_string(root->val) + "->" + s);
            }
        }

        if (root->right) {
            vector<string> leftRes = binaryTreePaths(root->right);
            for (string &s:leftRes) {
                res.push_back(to_string(root->val) + "->" + s);
            }
        }

        return res;
    }
};