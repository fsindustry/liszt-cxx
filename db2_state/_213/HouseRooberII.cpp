//
// Created by fsindustry on 2022/10/25.
//
#include <vector>

using namespace std;

// dynamic program
class Solution {
private:
    vector<int> cache;

    int maxSum(vector<int> &nums, int start, int end) {
        if (start > end) {
            return 0;
        }

        cache[end] = nums[end];
        for (int i = end; i >= start; i--) {
            int res = 0;
            for (int j = i; j <= end; j++) {
                if (j + 2 <= end) {
                    res = max(res, nums[j] + cache[j + 2]);
                } else {
                    res = max(res, nums[j]);
                }
            }
            cache[i] = res;
        }

        return cache[start];
    }

public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return nums[0];
        }

        // caution：cache values are different for the twice calculations.
        cache = vector<int>(n, -1);
        int v1 = maxSum(nums, 0, n - 2);
        cache = vector<int>(n, -1);
        int v2 = maxSum(nums, 1, n - 1);
        return max(v1, v2);
    }
};

// memory search
class Solution1 {
private:
    vector<int> cache;

    int maxSum(vector<int> &nums, int start, int end) {
        if (start > end) {
            return 0;
        }

        if (cache[start] != -1) {
            return cache[start];
        }

        int res = 0;
        for (int i = start; i <= end; i++) {
            res = max(res, nums[i] + maxSum(nums, i + 2, end));
        }
        return cache[start] = res;
    }

public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }

        // caution：cache values are different for the twice calculations.
        cache = vector<int>(n, -1);
        int v1 = maxSum(nums, 0, n - 2);
        cache = vector<int>(n, -1);
        int v2 = maxSum(nums, 1, n - 1);
        return max(v1, v2);
    }
};