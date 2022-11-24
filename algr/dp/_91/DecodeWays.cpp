//
// Created by fsindustry on 2022/10/19.
//
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// dynamic programming
class Solution {

private:

    vector<int> cache;

public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.length();
        cache = vector<int>(n + 1, -1);
        for (int start = n; start >= 0; start--) {
            if (start >= n) {
                cache[start] = 1;
                continue;
            }

            if (s[start] == '0') {
                cache[start] = 0;
                continue;
            }

            cache[start] = cache[start + 1];
            if (start + 1 < n && s.substr(start, 2) <= "26") {
                cache[start] += cache[start + 2];
            }
        }

        return cache[0];
    }
};

// memory search
class Solution1 {

private:

    vector<int> cache;

    int dfs(string &s, int start) {
        if (s.length() <= start) {
            return 1;
        }

        if (s[start] == '0') {
            return 0;
        }

        if (cache[start] != -1) {
            return cache[start];
        }

        int count = dfs(s, start + 1);

        if (start + 1 < s.length() && s.substr(start, 2) <= "26") {
            count += dfs(s, start + 2);
        }

        return cache[start] = count;
    }

public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        cache = vector<int>(s.length(), -1);
        return dfs(s, 0);
    }
};

// recursive: timeout
class Solution2 {

private:
    int dfs(string &s, int start) {
        if (s.length() <= start) {
            return 1;
        }

        if (s[start] == '0') {
            return 0;
        }

        int count = dfs(s, start + 1);

        if (start + 1 < s.length() && s.substr(start, 2) <= "26") {
            count += dfs(s, start + 2);
        }

        return count;
    }

public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        return dfs(s, 0);
    }
};

void test1() {
    Solution s;
    cout << s.numDecodings("12") << endl;
}

int main() {
    test1();
}