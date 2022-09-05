//
// Created by fsindustry on 2022/9/5.
//

#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
#include <cmath>

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
    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        vector<int> path;
        dfs(root, sum, path);
        return sum;
    }

    void dfs(TreeNode *root, int &sum, vector<int> &path) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            sum += num(path);
        }

        if (root->left) {
            dfs(root->left, sum, path);
        }

        if (root->right) {
            dfs(root->right, sum, path);
        }

        path.pop_back();
    }

    int num(vector<int> &path) {
        int res = 0;
        for (int i = 0; i < path.size(); i++) {
            res += path[i] * pow(10, path.size() - i - 1);
        }
        return res;
    }
};

void test1() {
    Solution s;
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << "result: " << s.sumNumbers(root) << endl;
}

int main() {
    test1();
}