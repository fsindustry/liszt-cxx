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

        int i0 = 0, i1 = -prices[0], i_pre_0 = 0;
        for (int i = 0; i < n; i++) {
            int tmp = i0;
            i0 = max(i0, i1 + prices[i]);
            i1 = max(i1, i_pre_0 - prices[i]);
            i_pre_0 = tmp;
        }
        return i0;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n) {
            return 0;
        }

        int cache[n][2];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                // i == 0
                cache[0][0] = 0;
                cache[0][1] = -prices[0];
                continue;
            }

            if (i == 1) {
                // i == 1
                cache[1][0] = max(cache[0][0], cache[0][1] + prices[1]);
                // 因为前一天不允许交易，故前一天和前2天的利润相同，故cache[-1][0] == cache[0][0]
                cache[1][1] = max(cache[0][1], -prices[1]);
                continue;
            }

            cache[i][0] = max(cache[i - 1][0], cache[i - 1][1] + prices[i]);
            // 第 i 天持有股票 = max( 昨天持有股票， 前天未持有股票今天买入股票 )
            cache[i][1] = max(cache[i - 1][1], cache[i - 2][0] - prices[i]);
        }
        return cache[n - 1][0];
    }
};