//
// Created by fsindustry on 2022/9/19.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
    string chMap[10]{
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };

    vector<string> res;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }

        findCombinations(digits, 0, "");
        return res;
    }

    void findCombinations(string &digits, int idx, const string &path) {
        if (idx == digits.length()) {
            res.push_back(path);
            return;
        }

        string &chs = chMap[digits[idx] - '0'];
        for (char ch: chs) {
            findCombinations(digits, idx + 1, path + ch);
        }
    }
};