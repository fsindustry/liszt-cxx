//
// Created by fsindustry on 2022/9/2.
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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        }

        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode *top = stack.top();
            stack.pop();

            if (top->left) {
                stack.push(top->left);
            }

            if (top->right) {
                stack.push(top->right);
            }

            swap(top);
        }

        return root;
    }

    static void swap(TreeNode *root) {
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};

class Solution1 {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        }

        invertTree(root->left);
        invertTree(root->right);
        swap(root);
        return root;
    }

    static void swap(TreeNode *root) {
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};



