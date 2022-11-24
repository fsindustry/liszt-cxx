//
// Created by fsindustry on 2022/10/22.
//
#include <vector>

using namespace std;

// dynamic program
class Solution {
private:
    int maxX, maxY;

    vector<vector<int>> cache;

    int inArea(int x, int y) {
        return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
    }

public:
    int uniquePaths(int m, int n) {
        maxX = m - 1, maxY = n - 1;
        cache = vector<vector<int>>(m, vector<int>(n, -1));
        cache[0][0] = 1;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (x == 0 && y == 0) {
                    continue;
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
        return cache[m - 1][n - 1];
    }
};

// memory search1: cache more
class Solution1 {
private:
    int maxX, maxY;

    vector<vector<int>> cache;

    int inArea(int x, int y) {
        return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
    }

    int countPath(int m, int n) {

        if (!inArea(m, n)) {
            return 0;
        }

        if (m == 0 && n == 0) {
            return 1;
        }

        if (cache[m][n] != -1) {
            return cache[m][n];
        }

        int count = 0;
        if (inArea(m - 1, n) && cache[m - 1][n] != -1) {
            count += cache[m - 1][n];
        } else {
            count += countPath(m - 1, n);
        }

        if (inArea(m, n - 1) && cache[m][n - 1] != -1) {
            count += cache[m][n - 1];
        } else {
            count += countPath(m, n - 1);
        }

        return cache[m][n] = count;
    }

public:
    int uniquePaths(int m, int n) {
        maxX = m - 1, maxY = n - 1;
        cache = vector<vector<int>>(m, vector<int>(n, -1));
        return countPath(m - 1, n - 1);
    }
};

// memory search2
class Solution2 {
private:
    int maxX, maxY;

    vector<vector<int>> cache;

    int inArea(int x, int y) {
        return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
    }

    int countPath(int m, int n) {

        if (!inArea(m, n)) {
            return 0;
        }

        if (m == 0 && n == 0) {
            return 1;
        }

        if (cache[m][n] != -1) {
            return cache[m][n];
        }

        return cache[m][n] = countPath(m - 1, n) + countPath(m, n - 1);
    }

public:
    int uniquePaths(int m, int n) {
        maxX = m - 1, maxY = n - 1;
        cache = vector<vector<int>>(m, vector<int>(n, -1));
        return countPath(m - 1, n - 1);
    }
};

// recursion: timeout
class Solution3 {
private:
    int maxX, maxY;

    int inArea(int x, int y) {
        return x >= 0 && x <= maxX && y >= 0 && y <= maxY;
    }

    int countPath(int m, int n) {

        if (!inArea(m, n)) {
            return 0;
        }

        if (m == 0 && n == 0) {
            return 1;
        }

        return countPath(m - 1, n) + countPath(m, n - 1);
    }

public:
    int uniquePaths(int m, int n) {
        maxX = m - 1, maxY = n - 1;
        return countPath(m - 1, n - 1);
    }
};
