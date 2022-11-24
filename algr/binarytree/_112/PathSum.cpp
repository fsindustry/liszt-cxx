//
// Created by fsindustry on 2022/9/3.
//


#include <algorithm>
#include <stack>

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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        stack<pair<TreeNode *, int>> stack;
        stack.push(make_pair(root, targetSum));

        while (!stack.empty()) {
            TreeNode *top = stack.top().first;
            int sum = stack.top().second;
            stack.pop();

            if (!top->left && !top->right && top->val == sum) {
                return true;
            }

            sum -= top->val;
            if (top->left) {
                stack.push(make_pair(top->left, sum));
            }

            if (top->right) {
                stack.push(make_pair(top->right, sum));
            }
        }

        return false;
    }
};

class Solution1 {
public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }

        if (!root->left && !root->right && root->val == targetSum) {
            return true;
        }

        return hasPathSum(root->left, targetSum - root->val)
               || hasPathSum(root->right, targetSum - root->val);
    }
};