//
// Created by fsindustry on 7/4/22.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> map1;
        for (int v: nums1) {
            map1[v]++;
        }

        vector<int> result;
        for (int v: nums2) {
            if (map1[v]) {
                result.push_back(v);
                map1[v]--;
            }
        }

        return result;
    }
};