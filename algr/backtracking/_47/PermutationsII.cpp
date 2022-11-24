//
// Created by fsindustry on 2022/9/23.
//
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }

        for (int i: nums) {
            countMap[i]++;
        }

        vector<int> path;
        findPerm(nums, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;
    unordered_map<int, int> countMap;

    void findPerm(vector<int> &nums, int idx, vector<int> &path) {
        if (nums.size() == idx) {
            res.push_back(path);
            return;
        }

        for (pair<int, int> p: countMap) {
            if (!p.second) {
                continue;
            }

            path.push_back(p.first);
            countMap[p.first]--;

            findPerm(nums, idx + 1, path);

            path.pop_back();
            // don't forget to recover the count during backtracking
            countMap[p.first]++;
        }
    }
};


class Solution1 {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }

        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> path;
        findPerm(nums, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

    void findPerm(vector<int> &nums, int idx, vector<int> &path) {
        if (nums.size() == idx) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                    continue;
                }

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

    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = Solution().permuteUnique(nums1);
    for (const vector<int> &tres: res1)
        printVec(tres);

    vector<int> nums2 = {2, 2, 1, 1};
    vector<vector<int>> res2 = Solution().permuteUnique(nums2);
    for (const vector<int> &tres: res2)
        printVec(tres);

    return 0;
}