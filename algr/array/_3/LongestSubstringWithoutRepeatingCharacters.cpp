//
// Created by fsindustry on 7/8/22.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // array must be initialized
        int countMap[256]{0};
        int l = 0, r = -1;
        int len = 0;
        while (l < s.size()) {
            if (r + 1 < s.size() && countMap[s[r + 1]] == 0) {
                countMap[s[++r]]++;
            } else { // r + 1 >= s.size() || countMap[r + 1] > 0
                len = max(len, r - l + 1);
                countMap[s[l++]]--;
            }
        }

        return len;
    }
};


void test1() {
    Solution solution;
    string s = "abcabcbb";
    vector<int> nums{2, 3, 1, 2, 4, 3};
    std::cout << "Output: " << solution.lengthOfLongestSubstring(s);
}


int main() {
    test1();
}