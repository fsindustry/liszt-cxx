//
// Created by fsindustry on 2022/11/26.
//
#include <vector>
#include <iostream>

using namespace std;

// dynamic program, less space cost
class Solution {
private:
    vector<int> mem;

public:
    int change(int amount, vector<int> &coins) {
        if (amount == 0) {
            return 1;
        }
        int n = coins.size();
        if (n == 0) {
            return 0;
        }
        mem = vector<int>(amount + 1, 0);
        mem[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c - coins[i] >= 0) {
                    mem[c] += mem[c - coins[i]];
                }
            }
        }
        return mem[amount];
    }
};

// dynamic program
class Solution1 {
private:
    vector<vector<int>> mem;

public:
    int change(int amount, vector<int> &coins) {
        if (amount == 0) {
            return 1;
        }
        int n = coins.size();
        if (n == 0) {
            return 0;
        }
        mem = vector<vector<int>>(n, vector<int>(amount + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c == 0) {
                    mem[i][0] = 1;
                    continue;
                }

                if (i == 0) {
                    mem[0][c] = 0;
                    if (coins[i] <= c && c % coins[i] == 0) {
                        mem[0][c] = 1;
                    }
                    continue;
                }

                mem[i][c] = mem[i - 1][c];
                if (c - coins[i] >= 0) {
                    mem[i][c] += mem[i][c - coins[i]];
                }
            }
        }
        return mem[n - 1][amount];
    }
};

// memory search
class Solution2 {
private:
    vector<vector<int>> mem;

    int dp(vector<int> &coins, int idx, int c) {
        if (c == 0) {
            return 1;
        }

        if (idx < 0 || c < 0) {
            return 0;
        }

        if (mem[idx][c] != -1) {
            return mem[idx][c];
        }

        int count = dp(coins, idx - 1, c);
        if (c - coins[idx] >= 0) {
            count += dp(coins, idx, c - coins[idx]);
        }

        return mem[idx][c] = count;
    }

public:
    int change(int amount, vector<int> &coins) {
        if (!amount) {
            return 1;
        }
        int n = coins.size();
        if (!n) {
            return 0;
        }
        mem = vector<vector<int>>(n, vector<int>(amount + 1, -1));
        return dp(coins, n - 1, amount);
    }
};

void test1() {
    Solution s;
    int amount = 5;
    vector<int> coins{1, 2, 5};
    cout << s.change(amount, coins) << endl;
}

int main() {
    test1();
}