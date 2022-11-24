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
    bool isSameTree(TreeNode *p, TreeNode *q) {

        stack<pair<TreeNode *, TreeNode *>> stack;
        stack.push(make_pair(p, q));
        while (!stack.empty()) {
            pair<TreeNode *, TreeNode *> pair = stack.top();
            TreeNode *n1 = pair.first;
            TreeNode *n2 = pair.second;
            stack.pop();

            if (!n1 && !n2) {
                continue;
            }

            if (!n1 || !n2) {
                return false;
            }

            if (n1->val != n2->val) {
                return false;
            }

            stack.push(make_pair(n1->left, n2->left));
            stack.push(make_pair(n1->right, n2->right));
        }

        return true;
    }
};

class Solution1 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        return p->val == q->val
               && isSameTree(p->left, q->left)
               && isSameTree(p->right, q->right);
    }
};

