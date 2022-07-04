//
// Created by fsindustry on 6/28/22.
//
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int maxArea = INT_MIN;
        while (l < r) {
            int area = min(height[l], height[r]) * (l - r);
            maxArea = max(maxArea, area);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};