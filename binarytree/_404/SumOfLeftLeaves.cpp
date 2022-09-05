//
// Created by fsindustry on 2022/9/3.
//

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
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int res = 0;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode *top = stack.top();
            stack.pop();

            if (top->left && !top->left->left && !top->left->right) {
                res += top->left->val;
            }

            if (top->left) {
                stack.push(top->left);
            }

            if (top->right) {
                stack.push(top->right);
            }
        }

        return res;
    }
};

class Solution1 {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int res = 0;
        // 注意：root为单节点的二叉树时，左叶子节点之和为0;
        if (root->left && !root->left->left && !root->left->right) {
            res += root->left->val;
        }

        if (root->left) {
            res += sumOfLeftLeaves(root->left);
        }

        if (root->right) {
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }
};