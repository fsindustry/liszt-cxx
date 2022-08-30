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
    int maxDepth(TreeNode *root) {
        if(!root){
            return 0;
        }

        int depth = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(true){

            int count = queue.size();
            if(0 == count){
                break;
            }
            depth++;

            while(count > 0){
                TreeNode* head = queue.front();
                queue.pop();

                if(head->left){
                    queue.push(head->left);
                }

                if(head->right){
                    queue.push(head->right);
                }

                count--;
            }
        }

        return depth;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode *root) {
        if(!root){
            return 0;
        }

        int depth = 0;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 1));
        while(!stack.empty()){

            pair<TreeNode*, int> pair = stack.top();
            stack.pop();
            TreeNode* cur = pair.first;
            int step = pair.second;

            if(!cur->left && !cur->right){
                depth = max(depth, step);
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
    int maxDepth(TreeNode *root) {
        if(!root){
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};