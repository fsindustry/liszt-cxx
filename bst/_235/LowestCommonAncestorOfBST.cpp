//
// Created by fsindustry on 2022/9/15.
//

#include <cassert>

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

        assert(p && q);
        if (!root) {
            return nullptr;
        }

        TreeNode *cur = root;
        while(cur){
            if(p->val < cur->val && q->val < cur->val){
                cur = cur->left;
            } else if(p->val > cur->val && q->val > cur->val){
                cur = cur->right;
            } else {
                break;
            }
        }

        return cur;
    }
};

class Solution1 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        assert(p && q);
        if (!root) {
            return nullptr;
        }

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};