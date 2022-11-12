//
// Created by fsindustry on 2022/11/5.
//
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// dynamic program
// space cost: O(n)
class Solution {
private:
    pair<int, int> dfs(TreeNode *node) {
        if (!node) {
            return {0, 0};
        }

        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        int rob = node->val + left.first + right.first;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);
        return {not_rob, rob};
    }

public:
    int rob(TreeNode *root) {
        if (!root) {
            return 0;
        }

        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
};

// dynamic program
class Solution1 {
private:
    unordered_map<TreeNode *, int> f, g;

    void maxSum(TreeNode *root) {
        if (!root) {
            return;
        }
        maxSum(root->left);
        maxSum(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(g[root->left], f[root->left]) + max(g[root->right], f[root->right]);
    }

public:
    int rob(TreeNode *root) {
        maxSum(root);
        return max(f[root], g[root]);
    }
};

// memory search
class Solution1 {
private:
    unordered_map<TreeNode *, int> choosedMap, unchoosedMap;

    int maxSum(TreeNode *root, bool choosed) {
        if (!root) {
            return 0;
        }

        if (choosed && choosedMap.find(root) != choosedMap.end()) {
            return choosedMap[root];
        } else if (!choosed && unchoosedMap.find(root) != unchoosedMap.end()) {
            return unchoosedMap[root];
        }

        int res = 0;
        if (choosed) {
            choosedMap[root] = res = max(res, root->val + maxSum(root->left, false) + maxSum(root->right, false));
        } else {
            int maxLeft = max(maxSum(root->left, true), maxSum(root->left, false));
            int maxRight = max(maxSum(root->right, true), maxSum(root->right, false));
            unchoosedMap[root] = res = maxLeft + maxRight;
        }
        return res;
    }

public:
    int rob(TreeNode *root) {
        return max(maxSum(root, true), maxSum(root, false));
    }
};