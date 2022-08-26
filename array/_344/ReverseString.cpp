//
// Created by fsindustry on 6/28/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s, l, r);
            l++, r--;
        }
    }

    void swap(vector<char> &s, int i1, int i2) {
        char tmp = s[i1];
        s[i1] = s[i2];
        s[i2] = tmp;
    }
};
