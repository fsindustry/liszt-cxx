#include "vector"
#include "iostream"
#include "ArrayUtils.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int k = 0; // [0,k)存放非0元素，元素个数即为k
        // 遍历nums，从左到右找到非0元素，依次放入到[0,k)区间；
        // 循环不变量：[0, k)表示非0元素的区间，随着k的增加，范围逐步扩大
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i != k) {
                    swap(nums[i], nums[k]);
                }
                k++;
            }
        }
    }
};


void test1() {
    ArrayUtils utils;
    vector<int> nums = {0, 1, 0, 3, 12};
    std::cout << "Input: " << utils.toString(nums) << endl;
//    std::cout << "Output: " << utils.toString(nums) << endl;
}

int main() {
    test1();
}

