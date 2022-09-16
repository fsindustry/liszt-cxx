//
// Created by fsindustry on 2022/9/16.
//
#include <cassert>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return nullptr;
        }

        // [l, r]为待查找区间
        return build(nums, 0, nums.size() -1);
    }

    TreeNode* build(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }

        if(l == r){
            return new TreeNode(nums[l]);
        }

        int mid = l + (r - l)/2;
        auto *root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid -1 );
        root->right = build(nums, mid + 1, r);
        return root;
    }
};