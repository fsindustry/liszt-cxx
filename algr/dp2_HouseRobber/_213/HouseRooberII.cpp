//
// Created by fsindustry on 2022/10/25.
//
#include <vector>

using namespace std;

// dynamic program
// space cost：O(1)
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        return max(
                dp(nums, 0, n - 2),
                dp(nums, 1, n - 1)
        );
    }

    int dp(vector<int> &nums, int start, int end) {
        int n1 = 0, n2 = 0, cur = 0;
        for (int i = end; i >= start; i--) {
            cur = max(n1, nums[i] + n2);
            n2 = n1;
            n1 = cur;
        }
        return cur;
    }
};

// dynamic program
class Solution1 {
private:
    vector<int> cache;

    int maxSum(vector<int> &nums, int start, int end) {
        if (start > end) {
            return 0;
        }

        cache[end] = nums[end];
        cache[end - 1] = max(nums[end], nums[end - 1]);
        for (int i = end - 2; i >= start; i--) {
            cache[i] = max(cache[i + 1], nums[i] + cache[i + 2]);;
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

        if (n == 2) {
            return max(nums[0], nums[1]);
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
class Solution2 {
private:
    vector<int> cache;

    int maxSum(vector<int> &nums, int start, int end) {
        if (start > end) {
            return 0;
        }

        if (cache[start] != -1) {
            return cache[start];
        }

        return cache[start] = max(maxSum(nums, start + 1, end), nums[start] + maxSum(nums, start + 2, end));
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

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        // caution：cache values are different for the twice calculations.
        cache = vector<int>(n, -1);
        int v1 = maxSum(nums, 0, n - 2);
        cache = vector<int>(n, -1);
        int v2 = maxSum(nums, 1, n - 1);
        return max(v1, v2);
    }
};