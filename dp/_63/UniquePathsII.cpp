//
// Created by fsindustry on 2022/10/22.
//
#include <vector>

using namespace std;

// dynamic program
class Solution {
private:
    int m, n;
    vector<vector<int>> cache;

    int inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, 0));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (obstacleGrid[x][y] == 1) {
                    cache[x][y] = 0;
                } else {
                    if (x == 0 && y == 0) {
                        cache[x][y] = 1;
                    } else {
                        int count = 0;
                        if (inArea(x - 1, y)) {
                            count += cache[x - 1][y];
                        }

                        if (inArea(x, y - 1)) {
                            count += cache[x][y - 1];
                        }
                        cache[x][y] = count;
                    }
                }
            }
        }
        return cache[m - 1][n - 1];
    }
};

// memory search
class Solution1 {
private:
    int m, n;
    vector<vector<int>> cache;

    int inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int countPath(vector<vector<int>> &grid, int x, int y) {

        if (!inArea(x, y)) {
            return 0;
        }

        if (grid[x][y] == 1) {
            return cache[x][y] = 0;
        }

        if (x == 0 && y == 0) {
            return cache[x][y] = 1;
        }

        if (cache[x][y] != -1) {
            return cache[x][y];
        }

        return cache[x][y] = countPath(grid, x - 1, y) + countPath(grid, x, y - 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, -1));
        return countPath(obstacleGrid, m - 1, n - 1);
    }
};

// recursion: timeout
class Solution2 {
private:
    int m, n;

    int inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int countPath(vector<vector<int>> &grid, int x, int y) {

        if (!inArea(x, y)) {
            return 0;
        }

        if (grid[x][y] == 1) {
            return 0;
        }

        if (x == 0 && y == 0) {
            return 1;
        }

        return countPath(grid, x - 1, y) + countPath(grid, x, y - 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return countPath(obstacleGrid, m - 1, n - 1);
    }
};