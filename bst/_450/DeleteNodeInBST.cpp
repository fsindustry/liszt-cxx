//
// Created by fsindustry on 2022/9/16.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return nullptr;
        }

        // if key in left sub tree, delete from left sub tree
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        } else if(key > root->val){ // if key in right sub tree, delete from right sub tree
            root->right = deleteNode(root->right, key);
        } else { // key equals to root.val，choose a new root, and delete current root
            if(!root->left){
                TreeNode *del = root;
                root = root->right;
                delete del;
            } else if(!root->right){
                TreeNode *del = root;
                root = root->left;
                delete del;
            } else {
                TreeNode *min = minNode(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }
        return root;
    }

    TreeNode* minNode(TreeNode* root){
        if(!root->left){
            return root;
        }
        return minNode(root->left);
    }
};