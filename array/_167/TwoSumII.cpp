//
// Created by fsindustry on 6/28/22.
//
#include <vector>
#include <stdexcept>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                // caution: the index value start from 1;
                return vector<int>{l + 1, r + 1};
            }

            if (numbers[l] + numbers[r] > target) {
                r--;
            }

            if (numbers[l] + numbers[r] < target) {
                l++;
            }
        }

        throw invalid_argument("Invalid Result: has no solution.");
    }
};