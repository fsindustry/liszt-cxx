//
// Created by fsindustry on 6/27/22.
//
# include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i != k) {
                    swap(nums, k, i);
                }
                k++;
            }
        }
    }

    inline void swap(std::vector<int> &arr, int idx1, int idx2) {
        int tmp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = tmp;
    }
};