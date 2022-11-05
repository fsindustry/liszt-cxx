//
// Created by fsindustry on 2022/10/25.
//
#include <vector>

using namespace std;

// dynamic program
class Solution {
private:
    vector<int> cache;

public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        cache = vector<int>(nums.size(), -1);
        cache[0] = nums[0];

        for (int start = 0; start < nums.size(); start++) {
            int res = 0;
            for (int i = start; i >= 0; i--) {
                res = max(res, nums[i] + (i - 2 >= 0 ? cache[i - 2] : 0));
            }
            cache[start] = res;
        }

        return cache[nums.size() - 1];
    }
};

// memory search
class Solution2 {
private:
    vector<int> cache;

    int maxSum(vector<int> &nums, int start) {
        if (start < 0) {
            return 0;
        }

        if (cache[start] != -1) {
            return cache[start];
        }
        int res = 0;
        for (int i = start; i >= 0; i--) {
            res = max(res, nums[i] + maxSum(nums, i - 2));
        }

        return cache[start] = res;
    }

public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        cache = vector<int>(nums.size(), -1);
        return maxSum(nums, nums.size() - 1);
    }
};

// dynamic program
class Solution3 {
private:
    vector<int> cache;

public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        cache = vector<int>(nums.size(), -1);
        cache[nums.size() - 1] = nums[nums.size() - 1];

        for (int start = nums.size() - 1; start >= 0; start--) {
            int res = 0;
            for (int i = start; i < nums.size(); i++) {
                res = max(res, nums[i] + (i + 2 < nums.size() ? cache[i + 2] : 0));
            }
            cache[start] = res;
        }

        return cache[0];
    }
};

// memory search
class Solution4 {
private:
    vector<int> cache;

    int maxSum(vector<int> &nums, int start) {
        if (start >= nums.size()) {
            return 0;
        }

        if (cache[start] != -1) {
            return cache[start];
        }
        int res = 0;
        for (int i = start; i < nums.size(); i++) {
            res = max(res, nums[i] + maxSum(nums, i + 2));
        }

        return cache[start] = res;
    }

public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        cache = vector<int>(nums.size(), -1);
        return maxSum(nums, 0);
    }
};
