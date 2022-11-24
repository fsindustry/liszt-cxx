//
// Created by fsindustry on 2022/10/7.
//
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    int move[4][2]{{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}};

    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void findIslands(vector<vector<char>> &grid, int x, int y) {

        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int newx = x + move[i][0];
            int newy = y + move[i][1];
            // only when the new point is valid and is a new island, we will flag it.
            if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1') {
                findIslands(grid, newx, newy);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        if (m == 0) {
            return 0;
        }
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                // only when got a island and not visited it, it is a new island;
                if (!visited[x][y] && grid[x][y] == '1') {
                    res++;
                    findIslands(grid, x, y);
                }
        return res;
    }
};