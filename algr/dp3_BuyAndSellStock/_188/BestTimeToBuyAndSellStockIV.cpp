//
// Created by fsindustry on 2022/11/7.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 优化：根据 k的取值范围决定策略
class Solution {
private:
    static int maxProfitUnlimitK(int n, vector<int> &prices) {
        int i0 = 0, i1 = -prices[0];
        for (int i = 0; i < n; i++) {
            i0 = max(i0, i1 + prices[i]);
            i1 = max(i1, i0 - prices[i]);
        }
        return i0;
    }

    static int maxProfitUnlimitK(int n, int K, vector<int> &prices) {
        int cache[n][K + 1][2];
        for (int i = 0; i < n; i++) {
            cache[i][0][0] = 0;
            cache[i][0][1] = -prices[0];
        }

        for (int k = 0; k <= K; k++) {
            cache[0][k][0] = 0;
            cache[0][k][1] = -prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= K; k++) {
                cache[i][k][0] = max(cache[i - 1][k][0], cache[i - 1][k][1] + prices[i]);
                cache[i][k][1] = max(cache[i - 1][k][1], cache[i - 1][k - 1][0] - prices[i]);
            }
        }

        return cache[n - 1][K][0];
    }

public:
    int maxProfit(int K, vector<int> &prices) {

        int n = prices.size();
        if (!n) {
            return 0;
        }

        if (K > n / 2) {
            return maxProfitUnlimitK(n, prices);
        } else {
            return maxProfitUnlimitK(n, K, prices);
        }
    }
};

class Solution1 {
public:
    int maxProfit(int K, vector<int> &prices) {

        int n = prices.size();
        if (!n) {
            return 0;
        }

        int cache[n][K + 1][2];
        memset(&cache, 0, n * (K + 1) * 2);

        // k == 0
        for (int i = 0; i < n; i++) {
            cache[i][0][0] = 0;
            // 无意义，故给个负数
            cache[i][0][1] = -prices[0];
        }

        // i == 0
        for (int k = 0; k <= K; k++) {
            cache[0][k][0] = 0;
            // 持有股票，则利润为负数
            cache[0][k][1] = -prices[0];
        }

        for (int i = 1; i < n; i++) { // 从第i天开始交易
            for (int k = 1; k <= K; k++) { // 交易了k次
                // 今天未持有 = max（昨天未持有&今天继续不持有的利润，昨天持有&今天卖出的利润）
                cache[i][k][0] = max(cache[i - 1][k][0], cache[i - 1][k][1] + prices[i]);
                // 今天持有的最大利润 = max（昨天持有&今天继续持有的利润，昨天未持有&今天买入的利润）
                cache[i][k][1] = max(cache[i - 1][k][1], cache[i - 1][k - 1][0] - prices[i]);
            }
        }

        return cache[n - 1][K][0];
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