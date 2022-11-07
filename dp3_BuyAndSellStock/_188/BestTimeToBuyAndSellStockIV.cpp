//
// Created by fsindustry on 2022/11/7.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<vector<int>>> dp;

public:
    int maxProfit(int K, vector<int> &prices) {

        int n = prices.size();
        if (!n) {
            return 0;
        }

        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(K + 1, vector<int>(2, 0)));

        // 第0次交易，不允许交易，故利润为0，也不可能持有股票；
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = -prices[0];
        }

        // 第0天，无交易，则不持有股票利润为0，也不可能持有股票；
        for (int k = 0; k <= K; k++) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }

        for (int i = 1; i < n; i++) { // 从第1天开始交易
            for (int k = K; k >= 1; k--) { // 一开始无交易，故可以交易K次
                // 今天未持有 = max（昨天未持有&今天继续不持有的利润，昨天持有&今天卖出的利润）
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                // 今天持有的最大利润 = max（昨天持有&今天继续持有的利润，昨天未持有&今天买入的利润）
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][K][0];
    }
};

void test1() {
    Solution s;
    int k = 2;
    vector<int> prices = {2, 4, 1};
    cout << s.maxProfit(k, prices) << endl;
}

int main() {
    test1();
}