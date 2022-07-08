//
// Created by fsindustry on 7/7/22.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = -1;
        int sum = 0;
        int len = nums.size() + 1;
        while (l < nums.size()) {
            // caution: nums.size returns unsigned int, r + 1 will be converted from int to unsigned int.
            if (r + 1 < nums.size() && sum < target) {
                sum += nums[++r];
            } else { // r >= nums.size || sum >= target
                sum -= nums[l++];
            }

            if (sum >= target) {
                len = min(len, r - l + 1);
            }
        }

        return len == nums.size() + 1 ? 0 : len;
    }
};

void test1() {
    Solution s;
    int target = 7;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    std::cout << "Output: " << s.minSubArrayLen(target, nums);
}


int main() {
    test1();
}