//
// Created by fsindustry on 2022/11/16.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (!n) {
            return 0;
        }

        int i0 = 0, i1 = -prices[0] - fee;
        for (int i = 0; i < n; i++) {
            i0 = max(i0, i1 + prices[i]);
            i1 = max(i1, i0 - prices[i] - fee);
        }

        return i0;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        if (!n) {
            return 0;
        }

        int cache[n][2];
        cache[0][0] = 0;
        cache[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; i++) {
            cache[i][0] = max(cache[i - 1][0], cache[i - 1][1] + prices[i]);
            cache[i][1] = max(cache[i - 1][1], cache[i - 1][0] - prices[i] - fee);
        }

        return cache[n - 1][0];
    }
};