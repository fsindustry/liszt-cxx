//
// Created by fsindustry on 2022/10/17.
//
#include <queue>
#include <vector>

using namespace std;

// dynamic programming
class Solution {
private:
    vector<int> cache;

public:
    int numSquares(int n) {
        assert(n >= 1);
        cache = vector<int>(n + 1, -1);
        cache[0] = 0;
        for (int num = 1; num <= n; num++) {
            int step = INT_MAX;
            for (int i = 1; num - i * i >= 0; i++) {
                step = min(step, 1 + cache[num - i * i]);
            }
            cache[num] = step;
        }

        return cache[n];
    }
};

// memory search
class Solution1 {
private:
    vector<int> cache;

    // return the min step of n
    int findMin(int n) {
        if (n == 0) {
            return 0;
        }

        if (cache[n] != -1) {
            return cache[n];
        }

        int step = INT_MAX;
        for (int i = 1; n - i * i >= 0; i++) {
            step = min(step, 1 + findMin(n - i * i));
        }
        cache[n] = step;
        return step;
    }

public:
    int numSquares(int n) {
        assert(n >= 1);
        cache = vector<int>(n + 1, -1);
        return findMin(n);
    }
};

// recursion: timeout
class Solution2 {
private:
    // return the min step of n
    int findMin(int n) {
        if (n == 0) {
            return 0;
        }

        int step = INT_MAX;
        for (int i = 1; n - i * i >= 0; i++) {
            step = min(step, 1 + findMin(n - i * i));
        }
        return step;
    }

public:
    int numSquares(int n) {
        assert(n >= 1);
        return findMin(n);
    }
};

// BFS
class Solution3 {
public:
    int numSquares(int n) {
        assert(n >= 1);

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
        throw invalid_argument("no solution");
    }
};