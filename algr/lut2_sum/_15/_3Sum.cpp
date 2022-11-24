//
// Created by fsindustry on 7/7/22.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int target = 0;
        unordered_map<int, int> countMap;
        for (int num: nums) {
            countMap[num]++;
        }

        vector<vector<int>> result;

        // special case 1. more than three zeros
        if (countMap[0] >= 3) {
            result.push_back({0, 0, 0});
        }

        // sort and remove duplications
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {

                // special case 2. has more than two nums[i]
                if (nums[i] * 2 + nums[j] == target && countMap[nums[i]] >= 2) {
                    result.push_back({nums[i], nums[i], nums[j]});
                }

                // special case 3. has more than two nums[j]
                if (nums[j] * 2 + nums[i] == target && countMap[nums[j]] >= 2) {
                    result.push_back({nums[j], nums[j], nums[i]});
                }

                // if nums_k exists, and k is after i and j
                int nums_k = target - nums[i] - nums[j];
                if (nums_k > nums[j] && countMap[nums_k] != 0) {
                    result.push_back({nums[i], nums[j], nums_k});
                }
            }
        }
        return result;
    }
};


class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int target = 0;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        int k = 0;
        while (k < nums.size()) {

            int i = k + 1;
            int j = nums.size() - 1;

            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[k]});

                    int val = nums[i];
                    // skip the repeat value composition
                    while (i < j && nums[i] == val) i++;
                    val = nums[j];
                    while (i < j && nums[j] == val) j--;
                } else if (sum < 0) {
                    int curr = i;
                    // skip the repeat value composition
                    while (i < j && nums[i] == nums[curr]) i++;
                } else {
                    int curr = j;
                    while (i < j && nums[j] == nums[curr]) j--;
                }
            }

            // shrink the window
            int val = nums[k];
            while (k < nums.size() && nums[k] == val) k++;
        }
        return result;
    }
};