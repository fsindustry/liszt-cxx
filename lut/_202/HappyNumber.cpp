//
// Created by fsindustry on 7/4/22.
//
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> calculated;
        while (true) {
            int result = calculate(n);

            if (result == 1) {
                return true;
            } else if (calculated.find(result) != calculated.end()) {
                return false;
            } else {
                calculated.insert(result);
                n = result;
            }
        }

    }

    int calculate(int n) {
        int sum = 0;
        while (n > 0) {
            int mod = n % 10;
            sum += mod * mod;
            n = n / 10;
        }
        return sum;
    }
};