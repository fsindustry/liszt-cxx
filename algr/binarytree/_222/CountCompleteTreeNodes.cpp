//
// Created by fsindustry on 2022/9/2.
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
    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int count = 0;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode *top = stack.top();
            stack.pop();
            count++;

            if (top->left) {
                stack.push(top->left);
            }

            if (top->right) {
                stack.push(top->right);
            }
        }

        return count;
    }
};

class Solution1 {
public:
    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }

        // 优化，当完全二叉树是满二叉树时，直接计算节点数
        int left = l_height(root);
        int right = r_height(root);
        if (left == right) {
            return (1 << left) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int l_height(TreeNode *root) {
        if (!root) {
            return 0;
        }

        return l_height(root->left) + 1;
    }

    int r_height(TreeNode *root) {
        if (!root) {
            return 0;
        }

        return r_height(root->right) + 1;
    }
};