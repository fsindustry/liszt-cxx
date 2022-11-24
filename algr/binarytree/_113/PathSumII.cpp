//
// Created by fsindustry on 2022/9/5.
//



#include <algorithm>
#include <stack>
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return {};
        }

        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, res, path);
        return res;
    }

    void dfs(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> &path) {

        path.push_back(root->val);
        if (!root->left && !root->right && root->val == targetSum) {
            res.push_back(path);
        }

        if (root->left) {
            dfs(root->left, targetSum - root->val, res, path);
        }

        if (root->right) {
            dfs(root->right, targetSum - root->val, res, path);
        }

        path.pop_back();
    }
};

