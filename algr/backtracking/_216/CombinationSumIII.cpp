//
// Created by fsindustry on 2022/9/29.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k > n) {
            return res;
        }

        vector<int> path;
        findSum(k, n, 1, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void findSum(int depth, int sum, int start, vector<int> &path) {
        if (depth == 0 && sum == 0) {
            res.push_back(path);
            return;
        }

        if (depth == 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (sum >= i) {
                path.push_back(i);
                findSum(depth - 1, sum - i, i + 1, path);
                path.pop_back();
            }
        }
    }
};