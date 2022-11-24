//
// Created by fsindustry on 2022/9/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        assert(m + n > 0);

        int i = m - 1;
        int j = n - 1;
        int l = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[l] = nums1[i--];
            } else {
                nums1[l] = nums2[j--];
            }
            l--;
        }

        while (j >= 0) {
            nums1[l--] = nums2[j--];
        }
    }
};