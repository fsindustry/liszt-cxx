//
// Created by fsindustry on 2022/10/7.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
private:
    int m, n;
    int move[4][2]{{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    bool inArea(int x, int y) const {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void bfs(vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        visited[x][y] = true;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            for (auto &i: move) {
                int newx = x + i[0];
                int newy = y + i[1];
                if (inArea(newx, newy) && !visited[newx][newy] && heights[x][y] <= heights[newx][newy]) {
                    visited[newx][newy] = true;
                    q.push(make_pair(newx, newy));
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size();
        if (0 == m) {
            return {};
        }
        n = heights[0].size();
        if (n == 0) {
            return {};
        }

        vector<vector<bool>> visitedP = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> visitedA = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int x = 0; x < m; x++) {
            if (!visitedP[x][0]) bfs(heights, x, 0, visitedP);
            if (!visitedA[x][n - 1]) bfs(heights, x, n - 1, visitedA);
        }
        for (int y = 0; y < n; y++) {
            if (!visitedP[0][y]) bfs(heights, 0, y, visitedP);
            if (!visitedA[m - 1][y]) bfs(heights, m - 1, y, visitedA);
        }

        vector<vector<int>> res;
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                if (visitedP[x][y] && visitedA[x][y]) {
                    res.push_back({x, y});
                }

        return res;
    }
};

class Solution1 {
private:
    int m, n;
    int move[4][2]{{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    bool inArea(int x, int y) const {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &visited) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int newx = x + move[i][0];
            int newy = y + move[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && heights[newx][newy] >= heights[x][y]) {
                dfs(heights, newx, newy, visited);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size();
        if (0 == m) {
            return {};
        }
        n = heights[0].size();
        if (n == 0) {
            return {};
        }

        vector<vector<bool>> visitedP = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> visitedA = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int x = 0; x < m; x++) {
            if (!visitedP[x][0]) dfs(heights, x, 0, visitedP);
            if (!visitedA[x][n - 1]) dfs(heights, x, n - 1, visitedA);
        }
        for (int y = 0; y < n; y++) {
            if (!visitedP[0][y]) dfs(heights, 0, y, visitedP);
            if (!visitedA[m - 1][y]) dfs(heights, m - 1, y, visitedA);
        }

        vector<vector<int>> res;
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                if (visitedP[x][y] && visitedA[x][y]) {
                    res.push_back({x, y});
                }

        return res;
    }
};

void test1() {
    Solution s;
    vector<vector<int>> heights{{1, 2, 2, 3, 5},
                                {3, 2, 3, 4, 4},
                                {2, 4, 5, 3, 1},
                                {6, 7, 1, 4, 5},
                                {5, 1, 1, 2, 4}};
    vector<vector<int>> res = s.pacificAtlantic(heights);
    for (auto &p: res) {
        cout << "[" << p[0] << ", " << p[1] << "]" << endl;
    }
}

int main() {
    test1();
}