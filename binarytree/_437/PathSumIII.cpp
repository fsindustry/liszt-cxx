//
// Created by fsindustry on 2022/9/15.
//

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
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return 0;
        }

        long res = findPath(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }

    long findPath(TreeNode *root, long targetSum) {
        if (!root) {
            return 0;
        }

        long res = 0;
        if (root->val == targetSum) {
            res += 1;
        }
        res += findPath(root->left, targetSum - root->val);
        res += findPath(root->right, targetSum - root->val);
        return res;
    }
};