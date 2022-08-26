//
// Created by fsindustry on 7/4/22.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        int sMap[256] = {0};
        int tMap[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (!sMap[s[i]]) {
                sMap[s[i]] = t[i];
            } else {
                if (sMap[s[i]] != t[i]) {
                    return false;
                }
            }

            if (!tMap[t[i]]) {
                tMap[t[i]] = s[i];
            } else {
                if (tMap[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};