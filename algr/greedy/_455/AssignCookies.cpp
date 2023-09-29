//
// Created by fsindustry on 2023/9/29.
//

#include<vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    int gi = 0, si = 0, res = 0;
    while (gi < g.size() && si < s.size()) {
      if (g[gi] <= s[si]) {
        gi++;
        si++;
        res++;
      } else {
        gi++;
      }
    }
    return res;
  }
};