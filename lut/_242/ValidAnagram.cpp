//
// Created by fsindustry on 7/4/22.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // caution: array need to be initialized in C++
        int sMap[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            sMap[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (!sMap[t[i] - 'a']) {
                return false;
            } else {
                sMap[t[i] - 'a']--;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    std::cout << s.isAnagram("fe", "ja");
}