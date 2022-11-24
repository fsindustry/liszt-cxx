//
// Created by fsindustry on 2022/9/29.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        if (candidates.empty()) {
            return res;
        }

        sort(candidates.begin(), candidates.end());
        vector<int> path;
        findSum(candidates, target, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void findSum(vector<int> &candidates, int target, int start, vector<int> &path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i - 1] == candidates[i]) {
                continue;
            }

            if (target >= candidates[i]) {
                path.push_back(candidates[i]);
                findSum(candidates, target - candidates[i], i + 1, path);
                path.pop_back();
            }
        }
    }
};