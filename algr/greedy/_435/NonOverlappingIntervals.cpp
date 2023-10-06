//
// Created by fsindustry on 2023/10/6.
//
#include<vector>

using namespace std;

bool cmpByEndIdx(const vector<int> &a, const vector<int> &b) {
  return a[1] < b[1];
}

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmpByEndIdx);
    int pre = 0, cur = 1, res = 1;
    while (cur < intervals.size()) {
      if (intervals[cur][0] >= intervals[pre][1]) {
        pre = cur;
        res++;
      }
      cur++;
    }

    return intervals.size() - res;
  }
};