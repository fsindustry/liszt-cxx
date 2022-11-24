//
// Created by fsindustry on 6/28/22.
//
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isVowel(s[l])) {
                l++;
                continue;
            }

            if (!isVowel(s[r])) {
                r--;
                continue;
            }

            swap(s, l, r);
            l++, r--;
        }
        return s;
    }

    bool isVowel(int ch) {
        if ('a' <= ch && ch <= 'z') {
            ch -= 32;
        }
        return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    void swap(string &s, int i1, int i2) {
        char tmp = s[i1];
        s[i1] = s[i2];
        s[i2] = tmp;
    }
};