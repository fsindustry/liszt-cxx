//
// Created by fsindustry on 8/10/22.
//

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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        int depth = 0;
        while (true) {
            int count = queue.size();
            if (0 == count) {
                break;
            }
            depth++;

            while (count > 0) {
                TreeNode *head = queue.front();
                queue.pop();

                if(!head->left && !head->right){
                    return depth;
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

        return depth;
    }
};