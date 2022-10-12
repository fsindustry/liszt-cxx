//
// Created by fsindustry on 2022/10/11.
//
#include <vector>

using namespace std;

// dynamic programming
class Solution {
private:
    vector<vector<int>> cache;

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> cache(n, vector<int>(n, INT32_MIN));
        for (int i = 0; i < n; i++) {
            cache[n - 1][i] = triangle[n - 1][i];
        }

        for (int depth = n - 2; depth >= 0; depth--) {
            for (int idx = 0; idx < triangle[depth].size(); idx++) {
                int left = cache[depth + 1][idx];
                int right = cache[depth + 1][idx + 1];
                cache[depth][idx] = triangle[depth][idx] + min(left, right);
            }
        }

        return cache[0][0];
    }
};

// memorized search
class Solution1 {
private:
    vector<vector<int>> cache;

    int findMin(vector<vector<int>> &triangle, int idx, int depth) {
        if (triangle.size() - 1 == depth) {
            return triangle[depth][idx];
        }

        if (cache[depth][idx] == INT32_MIN) {
            int left = findMin(triangle, idx, depth + 1);
            int right = findMin(triangle, idx + 1, depth + 1);
            cache[depth][idx] = triangle[depth][idx] + min(left, right);
        }

        return cache[depth][idx];
    }

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        cache = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), INT32_MIN));
        return findMin(triangle, 0, 0);
    }
};

// recursion: timeout
class Solution2 {
private:
    int findMin(vector<vector<int>> &triangle, int idx, int depth) {
        if (triangle.size() - 1 == depth) {
            return triangle[depth][idx];
        }

        int res = triangle[depth][idx];
        int left = findMin(triangle, idx, depth + 1);
        int right = findMin(triangle, idx + 1, depth + 1);
        res += min(left, right);
        return res;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        return findMin(triangle, 0, 0);
    }
};