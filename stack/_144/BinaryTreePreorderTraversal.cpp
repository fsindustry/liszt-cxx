//
// Created by fsindustry on 8/4/22.
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root) {
            result.push_back(root->val);

            vector<int> left = preorderTraversal(root->left);
            result.insert(result.end(), left.begin(), left.end());

            vector<int> right = preorderTraversal(root->right);
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }
};

class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }

private:
    void preorderTraversal(TreeNode *root, vector<int> &result) {
        if (root) {
            result.push_back(root->val);
            preorderTraversal(root->left, result);
            preorderTraversal(root->right, result);
        }
    }
};

class Solution2 {

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

    vector<int> preorderTraversal(TreeNode *root) {

        vector<int> result;
        if (!root) {
            return result;
        }
        stack<Frame *> stack;
        stack.push(new Frame(Cmd::go, root));
        while (!stack.empty()) {
            Frame *top = stack.top();
            stack.pop();
            if (top->cmd == Cmd::go) {
                if (top->node->right) {
                    stack.push(new Frame(Cmd::go, top->node->right));
                }

                if (top->node->left) {
                    stack.push(new Frame(Cmd::go, top->node->left));
                }

                stack.push(new Frame(Cmd::val, top->node));
            } else {
                assert(top->cmd == Cmd::val);
                result.push_back(top->node->val);
            }
            delete top;
        }
        return result;
    }
};

void test1() {
    Solution2 s;
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3, nullptr, nullptr), nullptr));
    vector<int> res = s.preorderTraversal(root);
    for (int v: res) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    test1();
}