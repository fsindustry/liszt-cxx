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
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }

        return height(root) != -1;
    }

    int height(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = height(root->left);
        if (-1 == left) {
            return -1;
        }

        int right = height(root->right);
        if (-1 == right) {
            return -1;
        }

        if (abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    }
};

class Solution1 {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }

        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};