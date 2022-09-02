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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmertric(root->left, root->right);
    }

    bool isSymmertric(TreeNode *left, TreeNode *right) {
        stack<pair<TreeNode *, TreeNode *>> stack;
        stack.push(make_pair(left, right));
        while (!stack.empty()) {
            TreeNode *left = stack.top().first;
            TreeNode *right = stack.top().second;
            stack.pop();

            if (!left && !right) {
                continue;
            }

            if (!left || !right) {
                return false;
            }

            if (left->val != right->val) {
                return false;
            }

            stack.push(make_pair(left->left, right->right));
            stack.push(make_pair(left->right, right->left));
        }
        return true;
    }
};

class Solution1 {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return isSymmertric(root->left, root->right);
    }

    bool isSymmertric(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }

        if (!left || !right) {
            return false;
        }

        return (left->val == right->val)
               && isSymmertric(left->left, right->right)
               && isSymmertric(left->right, right->left);
    }
};