//
// Created by fsindustry on 2022/10/7.
//
#include <vector>

using namespace std;

class Solution {
private:
    int res = 0;
    vector<bool> col, dia1, dia2;

    void findPos(int n, int rowIdx, vector<int> &row) {
        if (n == rowIdx) {
            res++;
            return;
        }

        for (int colIdx = 0; colIdx < n; colIdx++) {
            if (!col[colIdx] && !dia1[rowIdx + colIdx] && !dia2[rowIdx - colIdx + n - 1]) {
                row.push_back(colIdx);
                col[colIdx] = true;
                dia1[rowIdx + colIdx] = true;
                dia2[rowIdx - colIdx + n - 1] = true;

                findPos(n, rowIdx + 1, row);

                row.pop_back();
                col[colIdx] = false;
                dia1[rowIdx + colIdx] = false;
                dia2[rowIdx - colIdx + n - 1] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        if (1 == n) {
            return 1;
        }

        col = vector<bool>(n, false);
        dia1 = dia2 = vector<bool>(2 * n - 1, false);
        vector<int> row;
        findPos(n, 0, row);
        return res;
    }
};