//
// Created by fsindustry on 7/13/22.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int maxCount = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            map<pair<int, int>, int> countMap;
            for (int j = i + 1; j < points.size(); j++) {
                pair<int, int> s = slope(points[i], points[j]);
                countMap[s]++;
                maxCount = max(maxCount, countMap[s]);
            }
        }
        return maxCount + 1;
    }

    pair<int, int> slope(vector<int> &p1, vector<int> &p2) {
        int x = p2[0] - p1[0];
        int y = p2[1] - p1[1];
        if (x == 0) {
            return pair<int, int>{INT32_MAX, INT32_MAX};
        } else if (y == 0) {
            return pair<int, int>{0, 0};
        } else if (x < 0) {
            x = -x;
            y = -y;
        }

        int g = gcd(x, y);
        return pair<int, int>{x / g, y / g};
    }

    int gcd(int x, int y) {
        x = abs(x);
        y = abs(y);
        if (x < y) {
            x += y;
            y = x - y;
            x = x - y;
        }

        int tmp = x % y;
        while (tmp > 0) {
            x = y;
            y = tmp;
            tmp = x % y;
        }
        return y;
    }

};