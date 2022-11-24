//
// Created by fsindustry on 2022/10/11.
//
#include <vector>
#include <iostream>

using namespace std;

// dynamic programming
class Solution {
    int m, n;
    vector<vector<int>> cache;

    bool inArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

public:
    int minPathSum(vector<vector<int>> &grid) {

        m = grid.size();
        n = grid[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, INT32_MAX));

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (x == 0 && y == 0) {
                    cache[x][y] = grid[0][0];
                    continue;
                }

                if (inArea(x - 1, y) && inArea(x, y - 1)) {
                    cache[x][y] = grid[x][y] + min(cache[x - 1][y], cache[x][y - 1]);
                } else if (!inArea(x - 1, y)) {
                    cache[x][y] = grid[x][y] + cache[x][y - 1];
                } else {
                    cache[x][y] = grid[x][y] + cache[x - 1][y];
                }
            }
        }

        return cache[m - 1][n - 1];
    }
};

// memorized search
class Solution1 {
private:
    int m, n;
    vector<vector<int>> cache;

    bool inArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int minSum(vector<vector<int>> &grid, int x, int y) {
        if (x == 0 && y == 0) {
            return grid[x][y];
        }

        if (inArea(x - 1, y) && cache[x - 1][y] == INT32_MAX) {
            cache[x - 1][y] = minSum(grid, x - 1, y);
        }

        if (inArea(x, y - 1) && cache[x][y - 1] == INT32_MAX) {
            cache[x][y - 1] = minSum(grid, x, y - 1);
        }

        if (inArea(x - 1, y) && inArea(x, y - 1)) {
            return grid[x][y] + min(cache[x - 1][y], cache[x][y - 1]);
        } else if (!inArea(x - 1, y)) {
            return grid[x][y] + cache[x][y - 1];
        } else {
            return grid[x][y] + cache[x - 1][y];
        }
    }

public:
    int minPathSum(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, INT32_MAX));
        return minSum(grid, m - 1, n - 1);
    }
};

// recursion: timeout
class Solution2 {
private:
    int m, n;

    bool inArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int minSum(vector<vector<int>> &grid, int x, int y) {
        if (x == 0 && y == 0) {
            return grid[x][y];
        }

        int right = INT32_MAX, down = INT32_MAX;
        if (inArea(x - 1, y)) { // move right
            right = minSum(grid, x - 1, y);
        }

        if (inArea(x, y - 1)) { // move down
            down = minSum(grid, x, y - 1);
        }

        return grid[x][y] + min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        return minSum(grid, m - 1, n - 1);
    }
};

void test1() {
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3},
                                {4, 5, 6}};
    cout << "result: " << s.minPathSum(grid) << endl;
}

int main() {
    test1();
}
