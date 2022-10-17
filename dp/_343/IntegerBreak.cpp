//
// Created by fsindustry on 2022/10/17.
//
#include <algorithm>
#include <vector>

using namespace std;


// dynamic programming
class Solution {
private:
    vector<int> cache;

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

public:
    int integerBreak(int n) {
        assert(n >= 2);
        cache = vector<int>(n + 1, -1);

        // i can be treated as n
        for (int i = 2; i <= n; i++) {
            // break i into at least 2 int and get the max product, then save it into cache[i]
            for (int j = 1; j < i; j++) {
                cache[i] = max3(cache[i], j * (i - j), j * cache[i - j]);
            }
        }
        return cache[n];
    }
};

// memory search
class Solution1 {
private:
    vector<int> cache;

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    // break n into at least 2 int and get the max product
    int breakInteger(int n) {
        if (n == 2) {
            return 1;
        }

        if (cache[n] != -1) {
            return cache[n];
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max3(res, i * (n - i), i * breakInteger(n - i));
        }
        cache[n] = res;
        return res;
    }

public:
    int integerBreak(int n) {
        assert(n >= 2);
        cache = vector<int>(n + 1, -1);
        return breakInteger(n);
    }
};

// recursion: timeout
class Solution2 {
private:

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    // break n into at least 2 int and get the max product
    int breakInteger(int n) {
        if (n == 2) {
            return 1;
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max3(res, i * (n - i), i * breakInteger(n - i));
        }
        return res;
    }

public:
    int integerBreak(int n) {
        assert(n >= 2);
        return breakInteger(n);
    }
};