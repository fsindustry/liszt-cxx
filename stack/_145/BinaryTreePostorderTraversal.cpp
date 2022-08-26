//
// Created by fsindustry on 8/5/22.
//
#include <vector>
#include <stack>
#include <cassert>
#include <iostream>

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }

private:
    void postorderTraversal(TreeNode *root, vector<int> &result) {
        if (root) {
            postorderTraversal(root->left, result);
            postorderTraversal(root->right, result);
            result.push_back(root->val);
        }
    }
};

class Solution1 {
public:
    enum Cmd {
        go, val
    };

    class Frame {
    public:
        Cmd cmd;
        TreeNode *node;

        Frame(Cmd cmd, TreeNode *node) : cmd(cmd), node(node) {}
    };

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(!root){
            return result;
        }
        stack<Frame *> stack;
        stack.push(new Frame(Cmd::go, root));
        while (!stack.empty()) {
            Frame *top = stack.top();
            stack.pop();
            if (Cmd::go == top->cmd) {
                stack.push(new Frame(Cmd::val, top->node));
                if (top->node->right) {
                    stack.push(new Frame(Cmd::go, top->node->right));
                }
                if (top->node->left) {
                    stack.push(new Frame(Cmd::go, top->node->left));
                }
            } else {
                assert(Cmd::val == top->cmd);
                result.push_back(top->node->val);
            }
            delete top;
        }
        return result;
    }
};