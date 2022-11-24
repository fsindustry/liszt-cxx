//
// Created by fsindustry on 7/13/22.
//
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int target = 0;
        unordered_map<int, int> map1;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                map1[nums1[i] + nums2[j]]++;
            }
        }

        unordered_map<int, int> map2;
        for (int k = 0; k < nums3.size(); k++) {
            for (int l = 0; l < nums4.size(); l++) {
                map2[nums3[k] + nums4[l]]++;
            }
        }

        int result = 0;
        for (auto &e: map1) {
            if (map2[target - e.first] > 0) {
                result += e.second * map2[target - e.first];
            }
        }

        return result;
    }
};

class Solution1 {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int target = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                map[nums1[i] + nums2[j]]++;
            }
        }

        int result = 0;
        for (int k = 0; k < nums3.size(); k++) {
            for (int l = 0; l < nums4.size(); l++) {
                int left = target - nums3[k] - nums4[l];
                if (map[left] > 0) {
                    result += map[left];
                }
            }
        }

        return result;
    }
};

int test1() {
    Solution s;
    vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};
    cout << "Output: " << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
}

int main() {
    test1();
}