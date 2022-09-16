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
    int index;
public:
    int kthSmallest(TreeNode* root, int k) {
        index = 0;
        return kthSmallestNode(root, k)->val;
    }

    TreeNode* kthSmallestNode(TreeNode* root, int k){
        if(!root){
            return nullptr;
        }

        // find from left sub tree
        TreeNode *res = kthSmallestNode(root->left , k);
        if(res){
            return res;
        }

        // if current node is the kth node, just return
        if(++index == k){
            return root;
        }

        // find from right sub tree
        return kthSmallestNode(root->right, k);
    }
};