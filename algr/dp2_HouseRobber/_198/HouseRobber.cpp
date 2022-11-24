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

        int cur = 0, n1 = 0, n2 = 0;
        for (int i = n - 1; i >= 0; i--) {
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

public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        cache = vector<int>(nums.size(), -1);

        for (int start = 0; start < nums.size(); start++) {
            if (start == 0) {
                cache[start] = nums[0];
                continue;
            }
            if (start == 1) {
                cache[start] = max(nums[0], nums[1]);
                continue;
            }
            cache[start] = max(nums[start] + cache[start - 2], cache[start - 1]);
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

        return cache[start] = max(nums[start] + maxSum(nums, start - 2), maxSum(nums, start - 1));
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
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        cache = vector<int>(n, -1);

        for (int start = n - 1; start >= 0; start--) {
            if (start == n - 1) {
                cache[start] = nums[start];
                continue;
            }
            if (start == n - 2) {
                cache[start] = max(nums[start], nums[start + 1]);
                continue;
            }
            cache[start] = max(nums[start] + cache[start + 2], cache[start + 1]);
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
        return cache[start] = max(nums[start] + maxSum(nums, start + 2), maxSum(nums, start + 1));
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
