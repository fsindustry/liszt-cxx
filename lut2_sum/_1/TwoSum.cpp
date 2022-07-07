//
// Created by fsindustry on 7/7/22.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // ( num[i], i )
        unordered_map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++) {
            int expect = target - nums[i];
            if (countMap.find(expect) != countMap.end()) {
                return vector<int>{i, countMap[expect]};
            }
            countMap[nums[i]]=i;
        }

        throw invalid_argument("no solution.");
    }
};