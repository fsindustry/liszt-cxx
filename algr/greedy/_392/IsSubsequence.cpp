//
// Created by fsindustry on 2023/9/29.
//
#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {

    int si = 0, ti = 0;
    while (si < s.size() && ti < t.size()) {
      if (s[si] == t[ti]) {
        si++;
        ti++;
      } else {
        ti++;
      }
    }
    if (si == s.size()) {
      return true;
    } else {
      return false;
    }
  }
};