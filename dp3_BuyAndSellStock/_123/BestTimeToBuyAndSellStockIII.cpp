//
// Created by fsindustry on 2022/11/16.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n) {
            return 0;
        }

        int K = 2;
        int cache[n][K + 1][2];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= K; k++) {
                if (i == 0) {
                    cache[i][k][0] = 0;
                    cache[i][k][1] = -prices[0];
                    continue;
                }

                if (k == 0) {
                    cache[i][k][0] = 0;
                    cache[i][k][1] = -prices[0];
                    continue;
                }

                cache[i][k][0] = max(cache[i - 1][k][0], cache[i - 1][k][1] + prices[i]);
                cache[i][k][1] = max(cache[i - 1][k][1], cache[i - 1][k - 1][0] - prices[i]);
            }
        }

        return cache[n - 1][K][0];
    }
};