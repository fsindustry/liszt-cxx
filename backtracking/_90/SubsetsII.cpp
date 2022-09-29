//
// Created by fsindustry on 2022/9/29.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }

        sort(nums.begin(), nums.end());
        vector<int> path;
        for (int k = 0; k <= nums.size(); k++) {
            findCombines(nums, k, 0, path);
        }
        return res;
    }

private:
    vector<vector<int>> res;

    void findCombines(vector<int> &nums, int k, int start, vector<int> &path) {
        if (k == path.size()) {
            res.push_back(path);
            return;
        }

        int end = nums.size() - (k - path.size()) + 1;
        for (int i = start; i < end; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            path.push_back(nums[i]);
            findCombines(nums, k, i + 1, path);
            path.pop_back();
        }
    }
};