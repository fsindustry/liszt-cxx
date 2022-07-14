//
// Created by fsindustry on 7/14/22.
//
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long long> s;
        for (int i = 0; i < nums.size(); i++) {
            auto j = s.lower_bound((long long) nums[i] - t);
            if (j != s.end()
                && *j <= (long long) nums[i] + t) {
                return true;
            } else {
                s.insert((long long) nums[i]);
            }

            if (s.size() > k) {
                s.erase((long long) nums[i - k]);
            }
        }
        return false;
    }
};


int main() {

    set<int> s1{1, 2, 3};
    cout << "upper_bound: " << *s1.upper_bound(2) << "lower_bound: " << *s1.lower_bound(2) << endl;

    vector<int> nums{1, 2, 3, 1};
    int k = 3, t = 0;
    Solution s;
    cout << "Output: " << s.containsNearbyAlmostDuplicate(nums, k, t) << endl;
}