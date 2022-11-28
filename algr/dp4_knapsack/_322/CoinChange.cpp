//
// Created by fsindustry on 2022/11/28.
//
#include <vector>

using namespace std;

// dynamic program
class Solution {
private:
    vector<int> mem;

public:
    int coinChange(vector<int> &coins, int amount) {
        mem = vector<int>(amount + 1, amount + 1);
        mem[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin: coins) {
                if (i - coin >= 0) {
                    mem[i] = min(mem[i], mem[i - coin] + 1);
                }
            }
        }

        return mem[amount] == amount + 1 ? -1 : mem[amount];
    }
};

// memory search
class Solution1 {
private:
    vector<int> mem;

    int minCoin(vector<int> &coins, int amount) {
        if (!amount) {
            return 0;
        }
        if (amount < 0) {
            return -1;
        }

        if (mem[amount] != -2) {
            return mem[amount];
        }

        int minCount = INT32_MAX;
        for (int coin: coins) {
            int sub = minCoin(coins, amount - coin);
            if (sub == -1) {
                continue;
            }
            minCount = min(minCount, sub + 1);
        }
        return mem[amount] = minCount == INT32_MAX ? -1 : minCount;
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        mem = vector<int>(amount + 1, -2);
        return minCoin(coins, amount);
    }
};