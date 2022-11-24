//
// Created by fsindustry on 2022/9/27.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) {
            return res;
        }

        vector<int> path;
        findSum(candidates, target, 0, path);
        return res;
    }

private:
    vector<vector<int> > res;

    void findSum(vector<int> &candidates, int target, int start, vector<int> &path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                path.push_back(candidates[i]);
                findSum(candidates, target - candidates[i], i, path);
                path.pop_back();
            }

        }
    }
};