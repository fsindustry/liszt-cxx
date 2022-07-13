//
// Created by fsindustry on 7/13/22.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> countMap;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    countMap[distance(points[i], points[j])]++;
                }
            }

            for (auto &entry: countMap) {
                result += entry.second * (entry.second - 1);
            }
        }
        return result;
    }

    int distance(vector<int> &p1, vector<int> &p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }
};