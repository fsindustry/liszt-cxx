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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        int level = 0;
        while (true) {
            int count = queue.size();
            if (0 == count) {
                break;
            }
            level++;

            vector<int> list;
            while (count > 0) {
                TreeNode *head = queue.front();
                queue.pop();

                list.push_back(head->val);

                if (head->left) {
                    queue.push(head->left);
                }

                if (head->right) {
                    queue.push(head->right);
                }

                count--;
            }

            if (level % 2 == 0) {
                reverse(list.begin(), list.end());
            }

            result.push_back(list);
        }

        return result;
    }
};
