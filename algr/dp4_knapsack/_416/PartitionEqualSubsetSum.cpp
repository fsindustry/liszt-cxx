//
// Created by fsindustry on 2022/11/25.
//
#include <vector>
#include <iostream>

using namespace std;

// dynamic program，less space cost.
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (!n) {
            return false;
        }
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 2) {
            return false;
        }
        int C = sum / 2;
        bool cache[C + 1];
        memset(cache, false, C + 1);
        cache[0] = true;
        for (int i = 1; i < n; i++) {
            for (int c = C; c >= 0; c--) {
                if (c - nums[i] >= 0) {
                    cache[c] = cache[c] || cache[c - nums[i]];
                }
            }
        }

        return cache[C];
    }
};

// dynamic program
class Solution1 {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (!n) {
            return false;
        }
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 2) {
            return false;
        }
        int C = sum / 2;
        int cache[n][C + 1];
        memset(cache, -1, n * (C + 1));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= C; c++) {
                if (i == 0) {
                    cache[0][c] = (nums[i] == c);
                    continue;
                }
                if (c == 0) {
                    cache[i][0] = true;
                    continue;
                }

                if (c - nums[i] >= 0) {
                    cache[i][c] = cache[i - 1][c] || cache[i - 1][c - nums[i]];
                } else {
                    cache[i][c] = cache[i - 1][c];
                }
            }
        }

        return cache[n - 1][C];
    }
};

// memory search
class Solution2 {
private:
    vector<vector<int>> cache;

    bool dp(vector<int> &nums, int idx, int c) {
        if (c == 0) {
            return true;
        }
        if (c < 0 || idx < 0) {
            return false;
        }

        if (cache[idx][c] != -1) {
            return cache[idx][c];
        }

        return cache[idx][c] = dp(nums, idx - 1, c) ||
                               dp(nums, idx - 1, c - nums[idx]);
    }

public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (!n) {
            return false;
        }
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 2) {
            return false;
        }

        int C = sum / 2;
        cache = vector<vector<int>>(n, vector<int>(C + 1, -1));
        return dp(nums, n - 1, C);
    }
};

void test1() {
    vector<int> input = {1, 1};
    Solution s;
    cout << s.canPartition(input) << endl;
}

int main() {
    test1();
}