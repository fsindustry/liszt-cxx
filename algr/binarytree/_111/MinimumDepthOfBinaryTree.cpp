//
// Created by fsindustry on 2022/8/30.
//
#include <queue>
#include <algorithm>
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
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int depth = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(true){

            int count = queue.size();
            if(count == 0){
                break;
            }
            depth++;

            while(count>0){
                TreeNode* cur = queue.front();
                queue.pop();
                if(!cur->left && !cur->right){
                    return depth;
                }

                if(cur->left){
                    queue.push(cur->left);
                }

                if(cur->right){
                    queue.push(cur->right);
                }

                count--;
            }
        }

        return depth;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int depth = INT32_MAX;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 1));
        while(!stack.empty()){
            TreeNode* cur = stack.top().first;
            int step = stack.top().second;
            stack.pop();

            if(!cur->left && !cur->right){
                depth = min(depth, step);
            }

            if(cur->left){
                stack.push(make_pair(cur->left, step + 1));
            }

            if(cur->right){
                stack.push(make_pair(cur->right, step + 1));
            }
        }

        return depth;
    }
};

class Solution1 {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right) {
            return 1;
        }

        int res = INT32_MAX;
        if(root->left){
            res = min(minDepth(root->left) + 1, res);
        }

        if(root->right){
            res = min(minDepth(root->right) + 1, res);
        }

        return res;
    }
};
