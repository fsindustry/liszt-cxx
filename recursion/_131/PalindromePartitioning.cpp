//
// Created by fsindustry on 2022/9/19.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return res;
        }
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

    void dfs(string &s, int start, vector<string> path) {
        if (start >= s.length()) {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, path);
                path.pop_back();
            }
        }
    }

    static bool isPalindrome(string &s, int start, int end) {
        if (s.empty()) {
            return true;
        }

        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }

        return true;
    }
};