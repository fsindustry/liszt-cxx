//
// Created by fsindustry on 2022/9/27.
//
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k) {
            return res;
        }

        vector<int> path;
        findCombines(n, k, 1, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void findCombines(int n, int k, int start, vector<int> path) {
        if (k == path.size()) {
            res.push_back(path);
            return;
        }

        int end = n - (k - path.size()) + 1;
        for (int i = start; i <= end; i++) {
            path.push_back(i);
            findCombines(n, k, i + 1, path);
            path.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || n < k) {
            return res;
        }

        vector<int> path;
        findCombines(n, k, 1, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void findCombines(int n, int k, int start, vector<int> path) {
        if (k == path.size()) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {
            path.push_back(i);
            findCombines(n, k, i + 1, path);
            path.pop_back();
        }
    }
};