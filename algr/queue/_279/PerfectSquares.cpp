//
// Created by fsindustry on 2022/8/26.
//
#include <queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        // ( num, step )
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));

        vector<bool> visited(n + 1, false);

        while (!q.empty()) {

            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1; num - i * i >= 0; i++) {
                int left = num - i * i;
                // get the first perfect square must be the least one.
                if (left == 0) {
                    return step + 1;
                }
                if (!visited[left]) {
                    q.push(make_pair(left, step + 1));
                    visited[left] = true;
                }
            }
        }

        throw invalid_argument("no solution.");
    }
};