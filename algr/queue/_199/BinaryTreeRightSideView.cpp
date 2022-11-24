//
// Created by fsindustry on 8/10/22.
//

#include <vector>
#include <queue>
#include <algorithm>

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        while (true) {
            int count = queue.size();
            if (0 == count) {
                break;
            }

            while (count > 0) {
                TreeNode *head = queue.front();
                queue.pop();
                if (count == 1) {
                    result.push_back(head->val);
                }

                if (head->left) {
                    queue.push(head->left);
                }

                if (head->right) {
                    queue.push(head->right);
                }

                count--;
            }
        }

        return result;
    }
};