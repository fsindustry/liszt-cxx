//
// Created by fsindustry on 6/28/22.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isValid(s[l])) {
                l++;
                continue;
            }

            if (!isValid(s[r])) {
                r--;
                continue;
            }

            if (!isEquals(s[l], s[r])) {
                return false;
            } else {
                l++;
                r--;
            }
        }

        return true;
    }

    bool isDight(int ch) {
        return '0' <= ch && ch <= '9';
    }

    bool isAlphabet(int ch) {
        return 'a' <= ch && ch <= 'z'
               || 'A' <= ch && ch <= 'Z';
    }

    bool isValid(int ch) {
        return isDight(ch) || isAlphabet(ch);
    }

    bool isEquals(int ch1, int ch2) {
        if ('a' <= ch1 && ch1 <= 'z') {
            ch1 -= 32;
        }

        if ('a' <= ch2 && ch2 <= 'z') {
            ch2 -= 32;
        }

        return ch1 == ch2;
    }
};
