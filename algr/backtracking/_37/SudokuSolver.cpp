//
// Created by fsindustry on 2022/10/7.
//
#include <vector>

using namespace std;

class Solution {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;

    void dfs(vector<vector<char>> &board, int idx) {
        if (idx == spaces.size()) {
            valid = true;
            return;
        }

        auto [x, y] = spaces[idx];
        for (int digit = 0; digit < 9 && !valid; digit++) {
            if (!line[x][digit] && !column[y][digit] && !block[x / 3][y / 3][digit]) {
                line[x][digit] = column[y][digit] = block[x / 3][y / 3][digit] = true;

                board[x][y] = digit + '0' + 1;
                dfs(board, idx + 1);

                line[x][digit] = column[y][digit] = block[x / 3][y / 3][digit] = false;
            }
        }
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));

        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (board[x][y] == '.') {
                    spaces.emplace_back(x, y);
                } else {
                    int digit = board[x][y] - '0' - 1;
                    line[x][digit] = column[y][digit] = block[x / 3][y / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }
};