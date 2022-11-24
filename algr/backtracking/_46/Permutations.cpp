//
// Created by fsindustry on 2022/9/23.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }

        used = vector<bool>(nums.size(), false);
        vector<int> path;
        findPerm(nums, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

    void findPerm(vector<int> &nums, int idx, vector<int> &path) {
        if (idx == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;

                findPerm(nums, idx + 1, path);

                path.pop_back();
                used[i] = false;
            }
        }
    }
};

void printVec(const vector<int> &vec) {
    for (int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums[] = {1, 2, 3};
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

    vector<vector<int>> res = Solution().permute(vec);
    for (int i = 0; i < res.size(); i++)
        printVec(res[i]);

    return 0;
}