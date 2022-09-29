//
// Created by fsindustry on 2022/9/29.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }

        vector<int> path;
        res.push_back(path);
        for (int k = 1; k <= nums.size(); k++) {
            findCombinations(nums, k, 0, path);
        }
        return res;
    }

private:
    vector<vector<int>> res;

    void findCombinations(vector<int> &nums, int k, int start, vector<int> &path) {
        if (k == path.size()) {
            res.push_back(path);
            return;
        }

        int end = nums.size() - (k - path.size()) + 1;
        for (int i = start; i < end; i++) {
            path.push_back(nums[i]);
            findCombinations(nums, k, i + 1, path);
            path.pop_back();
        }
    }
};

void test1() {
    Solution s;
    vector<int> nums{1, 2, 3};
    s.subsets(nums);
}

int main() {
    test1();
}