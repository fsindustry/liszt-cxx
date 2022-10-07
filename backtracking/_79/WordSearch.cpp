//
// Created by fsindustry on 2022/10/5.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int m;
    int n;
    vector<vector<bool>> used;
    int move[4][2] = {{-1, 0},   // 左移
                      {0,  1},   // 上移
                      {1,  0},   // 右移
                      {0,  -1}}; // 下移

    bool inArea(int x, int y) const {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool find(vector<vector<char>> &board, string &word, int idx, int x, int y) {
        if (idx == word.length() - 1) {
            return word[idx] == board[x][y];
        }

        if (word[idx] == board[x][y]) {
            used[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int newx = x + move[i][0];
                int newy = y + move[i][1];
                if (inArea(newx, newy) && !used[newx][newy]) {
                    if (find(board, word, idx + 1, newx, newy)) {
                        return true;
                    }
                }
            }
            used[x][y] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        if (m == 0) {
            return false;
        }
        n = board[0].size();

        used = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                if (find(board, word, 0, x, y)) {
                    return true;
                }
            }
        }

        return false;
    }
};