//
// Created by fsindustry on 7/8/22.
//
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        int tMap[256]{0};
        for (char c: t) tMap[c]++;
        int sMap[256]{0};
        int len = s.size() + 1;
        int l = 0, r = -1, matched = 0;
        int startIdx = -1;
        while (l < s.size()) {

            if (r + 1 < s.size() && matched < t.size()) {
                r++;
                sMap[s[r]]++;
                if (sMap[s[r]] <= tMap[s[r]]) {
                    matched++;
                }
            } else {
                assert(matched <= t.size());

                if (matched == t.size() && r - l + 1 < len) {
                    startIdx = l;
                    len = r - l + 1;
                }

                sMap[s[l]]--;
                if (sMap[s[l]] < tMap[s[l]]) {
                    matched--;
                }
                l++;
            }
        }

        return startIdx != -1 ? s.substr(startIdx, len) : "";
    }
};


void test1() {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    std::cout << "Output: " << solution.minWindow(s, t) << std::endl;
}


int main() {
    test1();
}