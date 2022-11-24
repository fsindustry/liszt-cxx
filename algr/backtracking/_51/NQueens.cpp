//
// Created by fsindustry on 2022/10/7.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col, dia1, dia2;

    vector<string> printSolution(int n, vector<int> &row) {
        assert(n == row.size());
        vector<string> ele(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            ele[i][row[i]] = 'Q';
        }
        return ele;
    }

    void findPos(int n, int rowIdx, vector<int> &row) {
        if (n == rowIdx) {
            res.push_back(printSolution(n, row));
            return;
        }

        for (int colIdx = 0; colIdx < n; colIdx++) {
            if (!col[colIdx] && !dia1[rowIdx + colIdx] && !dia2[rowIdx - colIdx + n - 1]) {
                row.push_back(colIdx);
                col[colIdx] = true;
                dia1[rowIdx + colIdx] = true;
                dia2[rowIdx - colIdx + n - 1] = true;

                findPos(n, rowIdx + 1, row);

                col[colIdx] = false;
                dia1[rowIdx + colIdx] = false;
                dia2[rowIdx - colIdx + n - 1] = false;
                row.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = dia2 = vector<bool>(2 * n - 1, false);

        vector<int> row;
        findPos(n, 0, row);

        return res;
    }
};