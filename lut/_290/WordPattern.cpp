//
// Created by fsindustry on 7/4/22.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words = split(s, ' ');
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> pMap;
        unordered_map<string, char> sMap;
        for (int i = 0; i < pattern.length(); i++) {
            if (pMap[pattern[i]] == "") {
                pMap[pattern[i]] = words[i];
            } else {
                if (pMap[pattern[i]] != words[i]) {
                    return false;
                }
            }

            if (!sMap[words[i]]) {
                sMap[words[i]] = pattern[i];
            } else {
                if (sMap[words[i]] != pattern[i]) {
                    return false;
                }
            }
        }

        return true;
    }

    vector<string> split(string s, char spliter) {
        int l = 0;
        vector<string> words;
        for (int r = 0; r < s.length(); r++) {
            if (s[r + 1] == spliter) {
                words.push_back(s.substr(l, r - l + 1));
                r++;
                l = r + 1;
            }
        }

        if (l < s.length()) {
            words.push_back(s.substr(l, s.length() - l));
        }

        return words;
    }
};

int main() {
    Solution s;
    std::cout << s.wordPattern("abba", "dog cat cat dog");
}