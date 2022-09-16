//
// Created by fsindustry on 2022/9/16.
//

#include <cassert>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        if (root == nullptr) {
            return nullptr;
        }

        // current node is target
        if (root == p || root == q) {
            return root;
        }

        // find in left and right sub tree
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        }

        if (left) {
            return left;
        }

        if (right) {
            return right;
        }
        return nullptr;
    }
};

class Solution1 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        assert(root != nullptr && p != nullptr && q != nullptr);
        vector<TreeNode *> pPath, qPath;
        dfs(root, p, pPath);
        dfs(root, q, qPath);;

        TreeNode *target = nullptr;
        for (int i = 0; i < pPath.size() && i < qPath.size(); i++) {
            if (pPath[i] == qPath[i]) {
                target = pPath[i];
            } else {
                break;
            }
        }
        return target;
    }

    bool dfs(TreeNode *node, TreeNode *target, vector<TreeNode *> &vals) {
        if (!node) {
            return false;
        }

        vals.push_back(node);

        // find target, just return
        if (node == target) {
            return true;
        }

        // find in left sub tree, if found, just return;
        if (dfs(node->left, target, vals)) {
            return true;
        }

        // find in right sub tree, if found, just return;
        if (dfs(node->right, target, vals)) {
            return true;
        }

        // doesn't find in current path, rollback
        vals.pop_back();
        return false;
    }
};