//
// Created by fsindustry on 2022/9/15.
//
#include <vector>
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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

    bool isValidBST(TreeNode *root, long min, long max) {
        if (!root) {
            return true;
        }

        if (root->val < min || root->val > max) {
            return false;
        }

        if (root->left && root->left->val >= root->val) {
            return false;
        }

        if (root->right && root->right->val <= root->val) {
            return false;
        }

        return isValidBST(root->left, min, (long) root->val - 1)
               && isValidBST(root->right, (long) root->val + 1, max);
    }
};

class Solution1 {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }

        vector<int> vector;
        inOrderTraverse(root, vector);
        for (int i = 1; i < vector.size(); i++) {
            if (vector[i - 1] >= vector[i]) {
                return false;
            }
        }
        return true;
    }

    void inOrderTraverse(TreeNode *root, vector<int> &vector) {

        if (!root) {
            return;
        }

        inOrderTraverse(root->left, vector);
        vector.push_back(root->val);
        inOrderTraverse(root->right, vector);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }

        stack<TreeNode *> s;
        stack<long> minStack, maxStack;

        s.push(root);
        minStack.push(INT_MIN);
        maxStack.push(INT_MAX);

        while (!s.empty()) {

            TreeNode *cur = s.top();
            s.pop();
            long min = minStack.top();
            minStack.pop();
            long max = maxStack.top();
            maxStack.pop();

            if (cur->val < min || cur->val > max) {
                return false;
            }

            if (cur->left) {
                if (cur->left->val >= cur->val) {
                    return false;
                }
                s.push(cur->left);
                minStack.push(min);
                maxStack.push(cur->val - 1);
            }

            if (cur->right) {
                if (cur->right->val <= cur->val) {
                    return false;
                }
                s.push(cur->right);
                minStack.push(cur->val + 1);
                maxStack.push(max);
            }
        }
        return true;
    }
};