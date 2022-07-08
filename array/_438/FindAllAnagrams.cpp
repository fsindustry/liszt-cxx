//
// Created by fsindustry on 7/8/22.
//
#include <vector>
#include <string>
#include <iostream>
#include "../../util/ArrayUtils.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if (s.size() < p.size()) {
            return {};
        }

        int pMap[26]{0};
        for (char c: p) {
            pMap[c - 'a']++;
        }
        vector<int> result;
        int sMap[26]{0};
        int l = 0, r = -1;
        while (r + 1 < s.size()) {
            r++;
            sMap[s[r] - 'a']++;
            if (r - l + 1 > p.size()) {
                sMap[s[l] - 'a']--;
                l++;
            }

            if (r - l + 1 == p.size() && isMatched(pMap, sMap)) {
                result.push_back(l);
            }
        }
        return result;
    }

    bool isMatched(int a1[], int a2[]) {
        for (int i = 0; i < 26; i++) {
            if (a1[i] != a2[i]) {
                return false;
            }
        }
        return true;
    }
};

void test1() {
    ArrayUtils utils;
    Solution solution;
    string s = "abcabcbb", p = "";
    vector<int> nums{2, 3, 1, 2, 4, 3};
    vector<int> result = solution.findAnagrams(s, p);
    std::cout << "Output: " << utils.print(result);
}


int main() {
    test1();
}