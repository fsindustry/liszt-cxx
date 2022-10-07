//
// Created by fsindustry on 2022/10/7.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution1 {
private:
    int m, n;
    int move[4][2]{{0,  -1},
                   {1,  0},
                   {0,  1},
                   {-1, 0}};
    vector<vector<bool>> visited;
    queue<pair<int, int>> queue;

    bool inArea(int x, int y) const {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool findArea(vector<vector<char>> &board, int x, int y, vector<pair<int, int>> &path) {
        bool surrounded = true;
        visited[x][y] = true;
        queue.push(pair<int, int>(x, y));
        while (!queue.empty()) {
            x = queue.front().first;
            y = queue.front().second;
            path.emplace_back(x, y);
            queue.pop();
            for (auto &i: move) {
                int newx = x + i[0];
                int newy = y + i[1];
                if (!inArea(newx, newy)) {
                    surrounded = false;
                } else if (board[newx][newy] == 'O' && !visited[newx][newy]) {
                    visited[newx][newy] = true;
                    queue.push(pair<int, int>(newx, newy));
                }
            }

        }

        return surrounded;
    }

public:
    void solve(vector<vector<char>> &board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<pair<int, int>> path;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == 'O' && !visited[x][y]) {
                    path.clear();
                    if (findArea(board, x, y, path)) {
                        // flag points to 'X' which have been surrounded.
                        for (pair<int, int> &p: path) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};

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

    bool findArea(vector<vector<char>> &board, int x, int y, vector<pair<int, int>> &path) {

        visited[x][y] = true;
        path.push_back(make_pair(x, y));

        bool res = true;
        for (int i = 0; i < 4; i++) {
            int newx = x + move[i][0];
            int newy = y + move[i][1];

            // if current point is not surrended by 'X'，
            // then the area which contains current point can't be flipped,
            // but the point in this area must be flagged to visited status.
            if (!inArea(newx, newy)) {
                res = false;
            } else if (board[newx][newy] == 'O' && !visited[newx][newy]) {
                // if sub path find the area can't be flipped, then current point can't be flipped too.
                if (!findArea(board, newx, newy, path)) {
                    res = false;
                }
            }
        }
        return res;
    }

public:
    void solve(vector<vector<char>> &board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<pair<int, int>> path;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == 'O' && !visited[x][y]) {
                    path.clear();
                    if (findArea(board, x, y, path)) {
                        // flag points to 'X' which have been surrounded.
                        for (pair<int, int> &p: path) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};

void test1() {
    Solution s;
    vector<vector<char>> board(4, vector<char>(4));
    board = {{'X', 'X', 'X', 'X'},
             {'X', 'O', 'O', 'X'},
             {'X', 'X', 'O', 'X'},
             {'X', 'O', 'X', 'X'}};
    s.solve(board);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << board[i][j];
        cout << endl;
    }
}

void test2() {
    Solution s;
    vector<vector<char>> board(6, vector<char>(6));
    board = {{'O', 'O', 'O', 'O', 'X', 'X'},
             {'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'X', 'O', 'X', 'O', 'O'},
             {'O', 'X', 'O', 'O', 'X', 'O'},
             {'O', 'X', 'O', 'X', 'O', 'O'},
             {'O', 'X', 'O', 'O', 'O', 'O'}};
    s.solve(board);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            cout << board[i][j];
        cout << endl;
    }
}

void test3() {
    Solution s;
    vector<vector<char>> board(20, vector<char>(20));
    board = {{'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'X', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O'},
             {'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
             {'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'O'},
             {'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'O', 'O', 'X'},
             {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}};
    s.solve(board);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int main() {
    test1();
    test2();
    test3();
}