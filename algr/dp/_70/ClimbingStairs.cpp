//
// Created by fsindustry on 2022/10/11.
//
#include <vector>
#include <iostream>

using namespace std;

// dynamic programing
class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        cache[0] = 1;
        cache[1] = 1;
        for (int i = 2; i <= n; i++) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[n];
    }
};

// memorized search
class Solution1 {
private:
    vector<int> cache;

    int stepCount(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        if (cache[n] == -1) {
            cache[n] = stepCount(n - 1) + stepCount(n - 2);
        }

        return cache[n];
    }

public:
    int climbStairs(int n) {
        cache = vector<int>(n + 1, -1);
        return stepCount(n);
    }
};

// recursion: timeout
class Solution2 {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    Solution s;
    cout << "f(2) = " << s.climbStairs(2) << endl;
}